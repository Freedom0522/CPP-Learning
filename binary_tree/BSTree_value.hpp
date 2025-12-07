#pragma once
#include<iostream>

//key 模型

template<class K,class V>
struct BTreeNode
{
	BTreeNode<K,V>* _left;
	BTreeNode<K,V>* _right;
	K _key; //struct结构体储存类型信息
	V _value;
	BTreeNode(const K& key,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		,_value(value)
	{
	}//构造函数初始化
};

template<class K,class V>
class BTree
{
	typedef BTreeNode<K,V> Node;//结构体起别名
public:
	bool Insert(const K& key,const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}

		Node* cur = _root;//对象指针
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;//对指针解引用，指向对象中的成员，如果插入节点大于已有节点插入右子树

			}
			else if (cur->_key > key)
			{
				cur = cur->_left;//插入节点小于已有节点插入左子树
			}
			else
			{
				return false;
			}
		}
		/*cur = new Node(key);
		return true;*/

		//判断新节点插入已有节点的左边or右边
		if (parent->_key < key)
			parent->_right = new Node(key,value);
		else
			parent->_left = new Node(key,value);
		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//开始删除
				//1.左为空
				if (cur->_left == nullptr)
				{//这里也有问题
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}
					delete cur;
				}
				//2.右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				//3.左右都不为空
				else
				{
					/*Node* rightMinParent = nullptr;*/
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					cur->_key = rightMin->_key;

					if (rightMin == rightMinParent->_left)
						rightMinParent->_left = rightMin->_right;
					else
						rightMinParent->_right = rightMin->_right;
					//这里有问题
				   /*rightMinParent->_left = rightMin->_right;*/
					delete rightMin;
				}
				return true;
			}
		}
		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;//返回
		}
		_InOrder(root->_left);//一直走左子树
		std::cout << root->_key << ": "<<root->_value<<" ";
		/* std::cout << '\n';*/
		_InOrder(root->_right);//走右子树
	};

	void InOrder()
	{
		_InOrder(_root);
	}//中序遍历this指针

private:
	Node* _root = nullptr;

};

//void TestBSTree()
//{
//	BTree<int> t;
//	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//	t.InOrder();
//	std::cout << '\n';
//	//出现问题
//	t.Erase(7);
//	t.InOrder();
//	std::cout << '\n';
//
//	t.Erase(2);
//	t.InOrder();
//	std::cout << '\n';
//	t.Erase(8);
//	t.InOrder();
//	for (auto& e : a)
//	{
//		t.Erase(e);
//		t.InOrder();
//		std::cout << '\n';
//
//	}
//}

void TestBSTree_value()
{
	//BTree<std::string, std::string>dict;
	//dict.Insert("sort", "排序"); 
	//dict.Insert("string", "字符串");
	//dict.Insert("tree", "树");
	//dict.Insert("insert", "插入");

	//std::string str;
	//while (std::cin >> str)
	//{
	//	//为什么不用Node
	//	BTreeNode<std::string, std::string>* ret = dict.Find(str);
	//	if (ret)
	//	{
	//		std::cout << ret->_value << '\n';
	//	}
	//	else
	//	{
	//		std::cout << "无此单词" << '\n';
	//	}

	//}
	//统计次数
	std::string strArr[] = { "西瓜","苹果","西瓜","苹果","西瓜","香蕉","西瓜","樱桃","西瓜","西瓜" };
	BTree<std::string, int>countTree;
	for (auto str : strArr)
	{
		BTreeNode<std::string, int>* ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret -> _value++;
		}
	}
	countTree.InOrder();
}



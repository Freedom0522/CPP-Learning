#pragma once
#include <utility>
#include<iostream>
using std::pair;


template<class K,class V>
struct AVLTreeNode
{
    AVLTreeNode<K,V>*_left;
    AVLTreeNode<K,V>*_right;
    AVLTreeNode<K,V>*_parent;

    int _bf;//平衡因子
    pair<K,V> _kv;

    AVLTreeNode(const pair<K,V>& kv)
    :_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr)
    ,_kv(kv)
    ,_bf(0)
    {}
    /* data */
};

template<class K,class V>
class AVLTree
{
    typedef AVLTreeNode<K,V>Node;

    public:
    AVLTree():_root(nullptr){}
    bool Insert(const pair<K,V>& kv)
    {
        //1.先按搜索树的规则进行插入
        if(_root == nullptr)
        {
            _root  = new Node(kv);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;

        while(cur)
        {
            if(cur->_kv.first>kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if(cur->_kv.first<kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        if(parent->_kv.first<kv.first)
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
        else
        {
            parent->_left = cur;
            cur->_parent = parent;
        }
        //更新平衡因子
        while(parent)
        {
            if(cur == parent->_right)
            {
                parent->_bf++;
            }
            else{
                parent->_bf--;
            }
            if(parent->_bf == 0)
            {
                break;
            }
            else if(parent->_bf==1||parent->_bf==-1)
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if(parent->_bf ==2||parent->_bf==-2)
            {
                //parent所在子树出现不平衡问题，需要旋转处理
                //1.旋转前提保持他依旧是二叉搜索树
                //2.旋转成平衡树
                //3.对上层没有影响
                if(parent->_bf == 2)
                {
                    if(cur->_bf == 1)
                    {
                        RotateL(parent);
                    }
                    else if(cur->_bf == -1)
                    {
                        RotateRL(parent);
                    }
                }
                else if(parent->_bf == -2)
                {
                    if(cur->_bf == -1)
                    {
                        RotateR(parent);
                    }
                    else if(cur->_bf == 1)
                    {
                        //双旋
                        RotateLR(parent);
                    }
                }
                break;
                //旋转完成后，parent所在的树的高度恢复到了插入节点前高度
                //如果是子树，不对上层影响，更新结束
            }
        }
        return true;
    }

    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        Node* ppNode = parent->_parent;
        parent->_right = subRL;
        if(subRL)subRL->_parent=parent;
        subR->_left = parent;
        parent->_parent = subR;
        //1.原来parent是这棵树的根
        //2.parent为根的树只是整颗树的子树，改变链接关系，那么subR要顶替它的位置
        if(_root==parent)
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if(ppNode->_left == parent)ppNode->_left = subR;
            else
               ppNode->_right=subR;
            subR->_parent = ppNode;
        }
        parent->_bf = subR->_bf = 0;
    }
    void RotateR(Node* parent)
    {
        //parent发生失衡的节点
        Node* subL = parent->_left;//导致发生失衡的节点
        Node* subLR = subL->_right;
        Node* ppNode = parent->_parent;
        //旋转操作
        parent->_left = subLR;
        if(subLR)subLR->_parent = parent;
        subL->_right = parent;
        parent->_parent = subL;
        //处理根节点问题
        if(_root == parent)
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if(ppNode->_right == parent)ppNode->_right = subL;
            else ppNode->_left=subL;
            subL->_parent = ppNode;
        }
        parent->_bf = subL->_bf = 0;
    }

    // void Test(Node* parent)
    // {
    //     Node* suby = parent->_right;
    //     Node* subx = suby->_left;
    //     Node* subRR = subR->_right;
    //     Node* subRL = subR->_left;
    //     parent->_left = subRR;
    //     subR->_right = subRL;  
    // }

    void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;
        RotateR(parent->_right);
        RotateL(parent);
        //平衡因子的转换？
        if(bf == -1)
        {
            parent->_bf = 0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
        else if(bf == 1)
        {
            subR->_bf = 0;
            parent->_bf = -1;
            subRL->_bf = 0;
        }
        else if(bf == 0)
        {
            subR->_bf = 0;
            parent->_bf = 0;
            subRL->_bf = 0;
        }
    } 
    //左右双旋
    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(subL);
        RotateR(parent);

        if(bf == 1)
        {
            parent->_bf = 0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else if(bf == -1)
        {
            parent->_bf =1;
            subL->_bf =0;
            subLR->_bf =0;
        }
        else if(bf == 0)
        {
            parent->_bf = 0;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
    }

    void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;//返回
		}
		_InOrder(root->_left);//一直走左子树
		std::cout << root->_kv.first << ": "<<root->_kv.second<<" ";
		/* std::cout << '\n';*/
		_InOrder(root->_right);//走右子树
	};

	void InOrder()
	{
		_InOrder(_root);
	}//中序遍历this指针

    int Height(Node* root)
    {
        if(root == nullptr)return 0;
        int leftHeight = Height(root->_left);
        int rightHeight = Height(root->_right);

        return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
    }

    bool _IsBanlance(Node* root)
    {
        if(root == nullptr)return true;
        int leftHeight = Height(root->_left);
        int rightHeight = Height(root->_right);

        return abs(leftHeight - rightHeight) < 2 && _IsBanlance(root->_left)&&_IsBanlance(root->_right);
    }

    bool IsBalance()
    {
        return _IsBanlance(_root);
    }

    private:
    Node* _root;

};

void TestAVLTree()
{
    int  a[] = {16,3,7,11,9,26,18,14,15};
    AVLTree<int,int>t;
    for(auto e:a)
    {
        t.Insert(std::make_pair(e,e));
    }
    t.InOrder();
    std::cout<< t.IsBalance()<<'\n';
}

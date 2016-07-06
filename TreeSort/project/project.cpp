// project.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

//struct TreeNode;
//typedef boost::shared_ptr<TreeNode> TreeNodePtr;

template <typename T>
struct TreeNode
{
	~TreeNode()
	{
		std::wcout << L"~TreeNode\n";
	}
	std::auto_ptr<TreeNode> pLeft;
	std::auto_ptr<TreeNode> pRight;
	T key;
};
typedef TreeNode<std::wstring> TreeNodeWStr;
typedef TreeNode<std::string> TreeNodeStr;
typedef std::auto_ptr<TreeNodeWStr> TreeNodeWStrPtr;


using namespace std;

void InsertTree(TreeNodeWStrPtr& pTree, std::wstring const& str)
{
//	TreeNode* pTree = *ppTree;
	if (!pTree.get())
	{
		pTree.reset(new TreeNodeWStr);
		pTree->key = str;
//		pTree->pLeft = nullptr;
//		pTree->pRight = nullptr;
//		*ppTree = pTree;
	}
	else if (pTree->key > str)
	{	 
		InsertTree(pTree->pLeft, str);	
	}
	else
	{
		InsertTree(pTree->pRight, str);	
	}
}

void PrintTree(TreeNodeWStrPtr const&pTree)
{
	if (pTree.get() != nullptr)
	{
		 PrintTree(pTree->pLeft);
		 wcout << pTree->key;
		 PrintTree(pTree->pRight);
	}
}

void DelTree(TreeNodeWStrPtr &pTree)
{
	if (pTree.get() != nullptr)
	{
		 DelTree(pTree->pLeft);
		 DelTree(pTree->pRight);
		 pTree.reset();
//		 delete pTree;
//		 pTree = nullptr;
	}   
}

int _tmain(int argc, _TCHAR* /*(argv[]*/)
{
	argc;

	TreeNodeWStrPtr pTree;
	while (!cin.eof())
	{
		wchar_t ch = (wchar_t)wcin.get();

		if (ch == '\n')
		{
			break;
		}
		wcout << ch;
		InsertTree(pTree, std::wstring(1, ch));
	}
	wcout << L'\n';
	PrintTree(pTree);
	wcout << L'\n';
	//DelTree(pTree);
	return 0;
}


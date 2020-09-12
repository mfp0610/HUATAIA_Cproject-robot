// PathThinkerDoc.h : interface of the CPathThinkerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PATHTHINKERDOC_H__634CF864_E761_4728_9330_0FA0B21BDC99__INCLUDED_)
#define AFX_PATHTHINKERDOC_H__634CF864_E761_4728_9330_0FA0B21BDC99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>

#include "MapCell.h"

#define SLEEP_SECOND	100

class CPathThinkerDoc : public CDocument
{
protected: // create from serialization only
	CPathThinkerDoc();
	DECLARE_DYNCREATE(CPathThinkerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathThinkerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPathThinkerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
public:
	Cell	Cells[CELL_NUM][CELL_NUM];
	Cell	Origin;
	Cell	Target;
	
public:
	void	ResetCells();
	void	ClearPath();

	void	StartFind(void);
	
	// A-Star �����㷨
	bool	FindPath_AStar();
	
	// A-Star ���ӷ�����㷨����ǰһ��Ϊ����ο���
	bool	FindPath_AStar_Direct();
	
	// A-Star ֱ������Ŀ�ĵأ����ϰ����У����ܲ������·��
	bool	FindPath_BStar();


	void	FindPath();
	
private:
	bool	BuildPath();
	void	SleepMoment();
	void	UpdateView();
	void	UpdateView2();
	
// Generated message map functions
protected:
	//{{AFX_MSG(CPathThinkerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHTHINKERDOC_H__634CF864_E761_4728_9330_0FA0B21BDC99__INCLUDED_)

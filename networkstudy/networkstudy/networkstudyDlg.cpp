
// networkstudyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "networkstudy.h"
#include "networkstudyDlg.h"
#include "utility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CnetworkstudyDlg �Ի���




CnetworkstudyDlg::CnetworkstudyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CnetworkstudyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CnetworkstudyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CnetworkstudyDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_GETADDR, &CnetworkstudyDlg::OnBnClickedBtnGetaddr)
END_MESSAGE_MAP()


// CnetworkstudyDlg ��Ϣ�������

BOOL CnetworkstudyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CnetworkstudyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CnetworkstudyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CnetworkstudyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//-------------------------------------------------------------------------------------
//Description:
// This function maps a character string to a wide-character (Unicode) string
//
//Parameters:
// lpcszStr: [in] Pointer to the character string to be converted
// lpwszStr: [out] Pointer to a buffer that receives the translated string.
// dwSize: [in] Size of the buffer
//
//Return Values:
// TRUE: Succeed
// FALSE: Failed
//
//Example:
// MByteToWChar(szA,szW,sizeof(szW)/sizeof(szW[0]));
//---------------------------------------------------------------------------------------
BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode
	// string.
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, NULL, 0);
	if(dwSize < dwMinSize)
	{
		return FALSE;
	}

	// Convert headers from ASCII to Unicode.
	MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);  

	return TRUE;
}

//-------------------------------------------------------------------------------------
//Description:
// This function maps a wide-character string to a new character string
//
//Parameters:
// lpcwszStr: [in] Pointer to the character string to be converted
// lpszStr: [out] Pointer to a buffer that receives the translated string.
// dwSize: [in] Size of the buffer
//
//Return Values:
// TRUE: Succeed
// FALSE: Failed
//
//Example:
// MByteToWChar(szW,szA,sizeof(szA)/sizeof(szA[0]));
//---------------------------------------------------------------------------------------
BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)
{
	memset(lpszStr,0,dwSize * sizeof(char));
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,NULL,0,NULL,FALSE);
	if(dwSize < dwMinSize)
	{
		return FALSE;
	}

	WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,lpszStr,dwSize,NULL,FALSE);

	return TRUE;
}


void CnetworkstudyDlg::OnBnClickedBtnGetaddr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("Get addr"));

	SOCKADDR_IN		localaddr;
	BYTE			mac_address[6];
	CString output;


#define  DEVICE_NAME_LEN 128

	utility::getLocalAddress((char*)&localaddr.sin_addr.s_addr, mac_address);

	TCHAR sAddr[DEVICE_NAME_LEN+1];
	MByteToWChar((char *)inet_ntoa(localaddr.sin_addr),sAddr,DEVICE_NAME_LEN+1);

	output.Format(_T("%s  _%x:%x:%x:%x:%x:%x"), sAddr,mac_address[0],mac_address[1],mac_address[2],mac_address[3],mac_address[4],mac_address[5]);


	AfxMessageBox(output);



}

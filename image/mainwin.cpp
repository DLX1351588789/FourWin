#include "mainwin.h"

MainWin::MainWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	createActions ();
	createMenus();
	createToolBars();
	this -> setWindowState(Qt::WindowMaximized);
	fourWin = new FourWin(this);
	
	this -> setCentralWidget(fourWin);


}

MainWin::~MainWin()
{

}

void MainWin::createActions()
{
    //"��"����
    openFileAction = new QAction(QIcon(":/image/open.png"),QStringLiteral("��"),this);
    openFileAction -> setShortcut(tr("Ctrl+O"));
    openFileAction -> setStatusTip(QStringLiteral("��һ���ļ�"));
	connect(openFileAction,SIGNAL(triggered()),this,SLOT(openFileDir()));

    //"�˳�"����
    exitAction = new QAction(QStringLiteral("�˳�"),this);
    exitAction -> setShortcut(tr("Ctrl+Q"));
    exitAction -> setStatusTip(QStringLiteral("�˳�����"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWin::createMenus()
{
    //�ļ��˵�
    fileMenu = menuBar() -> addMenu(QStringLiteral("�ļ�"));
    fileMenu -> addAction(openFileAction);
    fileMenu -> addAction(exitAction);
}

void MainWin::createToolBars()
{
    //�ļ�������
    fileTool = addToolBar("File");
    fileTool -> addAction(openFileAction);
}

void MainWin::openFileDir()
{

	fourWin -> clearImage();
	fileDir = QFileDialog::getExistingDirectory(this,tr("select a folder"),"/");
	fourWin -> readImage(fileDir);
}


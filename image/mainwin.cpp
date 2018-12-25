#include "mainwin.h"

MainWin::MainWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	createActions ();
	createMenus();
	createToolBars();
	this->setWindowState(Qt::WindowMaximized);
	fourWin = new FourWin(this);
	
	this->setCentralWidget(fourWin);


}

MainWin::~MainWin()
{

}

void MainWin::createActions()
{
    //"打开"动作
    openFileAction =new QAction(QIcon(":/image/open.png"),QStringLiteral("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(QStringLiteral("打开一个文件"));
	connect(openFileAction,SIGNAL(triggered()),this,SLOT(openFileDir()));

    //"退出"动作
    exitAction =new QAction(QStringLiteral("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(QStringLiteral("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWin::createMenus()
{
    //文件菜单
    fileMenu =menuBar()->addMenu(QStringLiteral("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(exitAction);
}

void MainWin::createToolBars()
{
    //文件工具条
    fileTool =addToolBar("File");
    fileTool->addAction(openFileAction);
}

void MainWin::openFileDir()
{

	fourWin -> clearImage();
	fileDir = QFileDialog::getExistingDirectory(this,tr("select a folder"),"/");
	fourWin -> readImage(fileDir);
}


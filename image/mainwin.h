#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtWidgets/QMainWindow>
#include "ui_image.h"
#include "fourwin.h"
#include <QString>
#include <QFileDialog>

class MainWin : public QMainWindow
{
	Q_OBJECT

public:
	MainWin(QWidget *parent = 0);
	~MainWin();

	void createActions();                        	//创建动作
    void createMenus();                           	//创建菜单
    void createToolBars();                      	//创建工具栏
	
private:
	Ui::imageClass ui;

	QMenu *fileMenu;                           		//菜单栏

	QAction *openFileAction;                     	//文件菜单项
    QAction *exitAction;

	QToolBar *fileTool;                          	//工具栏

	FourWin *fourWin;								//四分窗

	QString fileDir;

private slots:
	void openFileDir();								//打开文件夹

};

#endif // IMAGE_H

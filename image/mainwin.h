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

	void createActions();                        	//��������
    void createMenus();                           	//�����˵�
    void createToolBars();                      	//����������
	
private:
	Ui::imageClass ui;

	QMenu *fileMenu;                           		//�˵���

	QAction *openFileAction;                     	//�ļ��˵���
    QAction *exitAction;

	QToolBar *fileTool;                          	//������

	FourWin *fourWin;								//�ķִ�

	QString fileDir;

private slots:
	void openFileDir();								//���ļ���

};

#endif // IMAGE_H

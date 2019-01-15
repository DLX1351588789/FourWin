#include "fourwin.h"
#include  <QGraphicsPixmapItem>
#include <QFile>
#include <QFileInfo>
#include <QtDebug>
#include <QEvent>

FourWin::FourWin(QWidget *parent)
	:QWidget(parent)
{
	mainSplitter = new QSplitter(Qt::Horizontal, 0);
	leftSplitter = new QSplitter(Qt::Vertical);
	rightSplitter = new QSplitter(Qt::Vertical);
	mainSplitter -> addWidget(leftSplitter);
	mainSplitter -> addWidget(rightSplitter);
	
	layout = new QGridLayout();
	layout -> addWidget(mainSplitter);
	setLayout(layout);
	
	fullScreen = false;

	for(int i = 0;i < 4; i++)
	{
		scene[i] = new QGraphicsScene;
		//scene[i] -> setSceneRect(QRectF(0,0,1000,800));
		view[i] = new QGraphicsView;
 	}

	for(int i = 0;i < 2; i++)
	{
		leftSplitter -> addWidget(view[i]);
		rightSplitter  -> addWidget(view[i + 2]);
	}

	for(int i = 0;i < 4;i++)
	{
		view[i] -> setScene(scene[i]);
		scene[i] -> installEventFilter(this);
	}
	it = NULL;
}

FourWin::~FourWin()
{

}
void FourWin::readImage(QDir director)
{
	dir = director;
	foreach(QFileInfo info,dir.entryInfoList(QStringList() << "*.jpg"))
	{
		QString fileName = info.absoluteFilePath();
		qDebug() << fileName << '\n';
		QImage *image = new QImage;
		image -> load(fileName);
		item.push_back(*image);	
	}	
	it = item.begin();

	
}

void FourWin::clearImage()
{
	item.clear();
	for(int i = 0;i < 4;i ++)
	{
		scene[i] -> clear();
	}
	
}

bool FourWin::eventFilter(QObject *watched, QEvent *event)
{
	if(event->type() == QEvent::GraphicsSceneMouseDoubleClick && fullScreen == false)
	{
		for(int i = 0;i < 4; i++)
		{
			if(scene[i] == watched)
			{
				view[i] -> show();
				qDebug() << "click" << i <<" window to full" << '\n';
			}
			else
			{
				view [i] -> hide();
			}
		}
		fullScreen = true;
		return true;
	}
	else if(event->type() == QEvent::GraphicsSceneMouseDoubleClick && fullScreen == true)
	{
        qDebug() << "click to shrink" << '\n';
		for(int i = 0; i < 4;i ++)
		{
			view[i] -> show();
		}
		fullScreen = false;
		return true;
	}
	return true;
	//if(watched==scene[0]  || watched==scene[1] || watched==scene[2] || watched==scene[3])
 //   {
	//	if(event->type() == QEvent::GraphicsSceneMousePress)
	//	{

	//		/*if(it == NULL)
	//		{
	//			QMessageBox::about(this,tr("tip"),tr("you should select a folder"));
	//			return false;
	//		}
	//
	//		if(it != item.end())
	//		{
	//			if(it == item.begin())
	//			{
	//									
	//				for(int i = 0; i < 4 ;i ++)
	//				{
	//					scene[i] -> setSceneRect(QRectF(0,0,it->width(),it->height()));
	//					scene[i] -> addPixmap(QPixmap::fromImage(*it));	
	//				}
	//				it ++;
	//			}
	//			else
	//			{
	//				for(int i = 0; i < 4 ;i ++)
	//				{
	//					scene[i] -> clear();
	//				}
	//				
	//				for(int i = 0; i < 4 ;i ++)
	//				{
	//					scene[i] -> setSceneRect(QRectF(0,0,it->width(),it->height()));
	//					scene[i] -> addPixmap(QPixmap::fromImage(*it));	
	//				}
	//				it ++;
	//			}
	//		}
	//		else 
	//		{
	//			for(int i = 0; i < 4 ;i ++)
	//			{
	//				scene[i] -> clear();
	//				scene[i] -> update();
	//			}*/
	//			it = item.begin();
	//		}
	//		return true;
	//	}	
}
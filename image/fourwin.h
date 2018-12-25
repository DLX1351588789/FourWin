#ifndef FOURWIN_H
#define FOURWIN_H
#include <QWidget>
#include <QSplitter>
#include <QGridLayout>
#include <QGraphicsView>
#include <QVector>
#include <QDir>
#include <QString>
#include <QMessageBox>

class FourWin : public QWidget
{
	Q_OBJECT

public:
	explicit FourWin(QWidget *parent = 0);
	~FourWin();
	void readImage(QDir);
	void clearImage();


private:
	QSplitter *mainSplitter;		
    QSplitter *leftSplitter; 
    QSplitter *rightSplitter; 

	QGridLayout *layout;

	QGraphicsScene *scene[4];
	QGraphicsView *view[4];
	
	bool fullScreen;
	QDir dir;

	QVector<QGraphicsPixmapItem*> item;
	QVector<QGraphicsPixmapItem*>::Iterator it;

protected:
	bool eventFilter(QObject *, QEvent *);
};

#endif
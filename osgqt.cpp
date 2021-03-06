#include "osgqt.h"
#include "./ui_osgqt.h"

#include "QtOsgView.h"
#include <QHBoxLayout>

osgqt::osgqt(QWidget *parent) : QWidget(parent), ui(new Ui::osgqt)
{
    ui->setupUi(this);

    // QT UI setting
    // QHBoxLayout* layout = new QHBoxLayout;
    // this->setLayout(layout);
    QMainWindow* mainwindow = new QMainWindow(this);
    ui->OSGlayout->addWidget(mainwindow);
    mainwindow->setWindowFlags(Qt::Widget);

    // OSG window setting
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile("/home/zed/Project/Libs/OpenSceneGraph/bin/OpenSceneGraph-Data/glider.osg");
    QtOsgView* ViewerWindow = new QtOsgView(mainwindow);
    ViewerWindow->setCameraManipulator(new osgGA::TrackballManipulator);
	ViewerWindow->addEventHandler(new osgViewer::WindowSizeHandler);
	ViewerWindow->addEventHandler(new osgViewer::StatsHandler);
	ViewerWindow->setSceneData(loadedModel.get());
    mainwindow->setCentralWidget(ViewerWindow);
}

osgqt::~osgqt()
{
    delete ui;
}


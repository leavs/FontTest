#include "mainwindow.h"
#include <QApplication>
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
#include <QtCore5Compat/QTextCodec>
#else
#include <QTextCodec>
#endif
#include <QDebug>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dir = QCoreApplication::applicationDirPath();
    QStringList m_fontList;
    m_fontList.clear();

    qDebug() << "Dir is " + dir;

    int lcdFontId = QFontDatabase::addApplicationFont(dir + "/simhei.ttf"); // the simhei.ttf is from windows system(%windir%\fonts)
    if (lcdFontId != -1)
    {
        qDebug() << "fond simhei.ttf";
        m_fontList << QFontDatabase::applicationFontFamilies(lcdFontId);
    }

    if (!m_fontList.isEmpty())      // first way: put fonts in directory same with program.
    {
        QFont font;
        font.setFamily(m_fontList.at(0));
        a.setFont(font);
        qDebug() << "Set simhei font";
    }else{                          // second way: put fonts in system fonts directory.
        QFont font;
        font.setPointSize(30);
        // *.ttf need be putted in /usr/lib/fonts directory. the *.ttf file can be got from windows (%windir%\fonts)
        // after you putted the fonts file, push "Debug" can get the font name from qDebug output.
        // then you can use the Name in follow codes. such as:
        // Now is chinese font:
        // "FangSong"
        // "KaiTi"
        // "SimHei"
        font.setFamily("FangSong");   //simfang.ttf
        //font.setFamily("KaiTi");  //simkai.ttf
        //font.setFamily("SimHei"); //simhei.ttf
        a.setFont(font);
    }

    MainWindow w;
    w.show();
    w.showFullScreen();

    return a.exec();
}

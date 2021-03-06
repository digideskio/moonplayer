#ifndef YOUTUBEDLBRIDGE_H
#define YOUTUBEDLBRIDGE_H

#include "parserbridge.h"

class YoutubeDLBridge : public ParserBridge
{
    Q_OBJECT
public:
    explicit YoutubeDLBridge(QObject *parent = 0);
    ~YoutubeDLBridge();

protected:
    void runParser(const QString &url);

private:
    QProcess *process;
    QWidget *msgWindow;

private slots:
    void parseOutput(void);
};

extern YoutubeDLBridge youtubedl_bridge;

#endif // YOUTUBEDLBRIDGE_H

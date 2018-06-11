#ifndef COMMANDPART_H
#define COMMANDPART_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <tvariantanimation.h>
#include "terminalpart.h"
#include "terminalwidget.h"

class TerminalWidget;

namespace Ui {
    class CommandPart;
}

class CommandPart : public QWidget
{
        Q_OBJECT

    public:
        explicit CommandPart(TerminalWidget* parentTerminal, QWidget *parent = 0);
        ~CommandPart();

    public slots:
        void setCommandText(QString text);
        void setReturnValue(int retval);
        void executeCommand(int height, QString command);
        void appendOutput(QString text);
        void executeWidget(QWidget* widget);
        void setEnvironment(QProcessEnvironment env);

    signals:
        void finished(int exitCode);

    private slots:
        void on_expandButton_clicked();

    private:
        Ui::CommandPart *ui;
        TerminalWidget* parentTerminal;
        QLabel* inbuiltOutputLabel = nullptr;
        QStringList outputLines;
        TerminalPart* currentTerminal;
        QProcessEnvironment env;
        bool expanded = true;
};

#endif // COMMANDPART_H

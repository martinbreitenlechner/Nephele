#ifndef SCRIPT_LOG_HANDLER_HPP
#define SCRIPT_LOG_HANDLER_HPP

#include <QObject>

namespace talorion{



    class script_log_handler : public QObject
    {
        Q_OBJECT
    private:
        enum severity{ UNKNOWN, INFO, DEBUG, WARNING, ERROR, FATAL };

    public:
        explicit script_log_handler(QObject *parent = 0);

        Q_INVOKABLE void write(const QString& string, const QString& color);

        Q_INVOKABLE void write(const QString& string);

        Q_INVOKABLE void log_info(const QString& msg);

        Q_INVOKABLE void log_debug(const QString& msg);

        Q_INVOKABLE void log_warning(const QString& msg);

        Q_INVOKABLE void log_error(const QString& msg);

        Q_INVOKABLE void log_fatal(const QString& msg);

    signals:
        void script_message(const QString& string, const QString& color);

    public slots:

    private:
        void log(severity sev, const QString& msg, const QString& color);

        QString time_to_string();

        QString severity_to_string(severity sev);

    };
}

#endif // SCRIPT_LOG_HANDLER_HPP
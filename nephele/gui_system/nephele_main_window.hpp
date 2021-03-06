#ifndef NEPHELE_MAIN_WINDOW_HPP
#define NEPHELE_MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QJsonDocument>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMap>
#include <QtCore>


namespace talorion {

    class flowControllerView;
    class digital_view;
    class tcp_box_view;
    class script_editor_window;
    class settings_dialog;
    class config_file;
    class quick_script_widget;

    class nephele_main_window : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit nephele_main_window(QWidget *par = 0);
        ~nephele_main_window();
        Q_DISABLE_COPY(nephele_main_window)

        void setCfg_hdl(config_file *value);
        void readSettings();

    signals:
        void send_custom_command(const QString& cm);

        void change_set_value(int m_entity, double value);

    protected:
        virtual void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

    private:
        void createActions();
        void createMenus();
        void createToolBars();
        void createStatusBar();

        bool maybeSave();

        void loadFile(const QString &fileName);
        bool saveFile(const QString &fileName);
        void setCurrentFile(const QString &fileName);

        //void read(const QJsonObject &json);
        //void write(QJsonObject &json) const;

        void zero_all();

    private:
        QString curFile;
        bool modified;
        //QGridLayout* mainLayout;
        script_editor_window* script_wnd;
        settings_dialog* sett_dlg;
        QMap<int, flowControllerView* > fc_views;
        QMap<int, digital_view* > dig_views;
        QMap<int, tcp_box_view* > boxes;

        QMenu *fileMenu;
        QMenu *scriptMenu;
        QMenu *toolsMenu;
        QMenu *helpMenu;
        QMenu *viewMenu;

        QToolBar *fileToolBar;
        QToolBar *scriptToolBar;

        QAction *scriptEditAct;

        QAction *optionsEditAct;
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;
        QAction *saveAsAct;
        QAction *exitAct;

        QAction *aboutAct;
        QWidget *central_wdgt;

        config_file *cfg_hdl;

        quick_script_widget* qs_widget;


    private slots:
        void displayCustomResponse(const QString& cm);
        void dispatchCommand();
        void add_box(int entity);
//        void addAIV(int entity);
//        void addAOV(int entity);
//        void addAV(int entity);
//        void addDIV(int entity);
//        void addDOV(int entity);
//        void addDIOV(int entity);
        //void slot_act_value_changed(int entity);
        //void slot_set_value_changed(int entity);

        void open_script_window();

        void newFile();
        void open();
        bool save();

        bool saveAs();
        void about();
    };
}

#endif // NEPHELE_MAIN_WINDOW_HPP

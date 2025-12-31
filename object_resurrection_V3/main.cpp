#include <QComboBox>
#include <iostream>
#include <fstream>
#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
#include <QLabel>
#include <QApplication>
#include <QDebug>
#include "seqList.h"
#include "Account.h"
#include "Kinds.h"
#include "Convert.h"
#include <cstring>
#include <string>
#include <QElapsedTimer>
#include <QStringConverter>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QFile>
#include <vector>
#include <QTableWidgetItem>
#include <QDockWidget>

using namespace std;

string ID; // 联系人账号信息（全局变量）

// 注册输入框类，继承自QDialog
class RegisterDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    RegisterDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("物品复活软件-注册");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 400);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建第一个输入框和标签（用户名输入）
        QLabel *label1 = new QLabel("请输入用户名：");
        input1 = new QLineEdit();
        layout->addWidget(label1);
        layout->addWidget(input1);

        // 创建第二个输入框和标签（密码输入）
        QLabel *label2 = new QLabel("请输入密码：");
        input2 = new QLineEdit();
        input2->setEchoMode(QLineEdit::Password);//隐藏密码输入
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建第三个输入框和标签（确认密码输入）
        QLabel *label3 = new QLabel("请确认密码：");
        input3 = new QLineEdit();
        input3->setEchoMode(QLineEdit::Password);//隐藏密码输入
        layout->addWidget(label3);
        layout->addWidget(input3);

        // 创建第四个输入框和标签（住址输入）
        QLabel *label4 = new QLabel("请输入住址：");
        input4 = new QLineEdit();
        layout->addWidget(label4);
        layout->addWidget(input4);

        // 创建第五个输入框和标签（联系人电话输入）
        QLabel *label5 = new QLabel("请输入联系人电话：");
        input5 = new QLineEdit();
        layout->addWidget(label5);
        layout->addWidget(input5);

        // 创建第六个输入框和标签（联系人邮箱输入）
        QLabel *label6 = new QLabel("请输入联系人邮箱：");
        input6 = new QLineEdit();
        layout->addWidget(label6);
        layout->addWidget(input6);

        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &RegisterDialog::accept);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }
    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }
    // 获取第三个输入框内容
    QString getInput3() const { return input3->text(); }
    // 获取第三个输入框内容
    QString getInput4() const { return input4->text(); }
    // 获取第三个输入框内容
    QString getInput5() const { return input5->text(); }
    // 获取第三个输入框内容
    QString getInput6() const { return input6->text(); }


private:
    QLineEdit *input1;  // 用户名输入框
    QLineEdit *input2;  // 密码输入框
    QLineEdit *input3;  // 密码确认框
    QLineEdit *input4;  // 住址输入框
    QLineEdit *input5;  // 电话输入框
    QLineEdit *input6;  // 邮箱输入框
};

// 管理员添加类型输入框类，继承自QDialog
class AddKindDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    AddKindDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("管理员-添加物品类型");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 400);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建第一个输入框和标签（物品类型）
        QLabel *label1 = new QLabel("请输入物品类型：");
        input1 = new QLineEdit();
        layout->addWidget(label1);
        layout->addWidget(input1);

        // 创建第二个输入框和标签（属性1）
        QLabel *label2 = new QLabel("请输入属性1：");
        input2 = new QLineEdit();
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建第三个输入框和标签（属性2）
        QLabel *label3 = new QLabel("请输入属性2：");
        input3 = new QLineEdit();
        layout->addWidget(label3);
        layout->addWidget(input3);

        // 创建第四个输入框和标签（属性3）
        QLabel *label4 = new QLabel("请输入属性3：");
        input4 = new QLineEdit();
        layout->addWidget(label4);
        layout->addWidget(input4);

        // 创建第五个输入框和标签（属性4）
        QLabel *label5 = new QLabel("请输入属性4：");
        input5 = new QLineEdit();
        layout->addWidget(label5);
        layout->addWidget(input5);

        // 创建第六个输入框和标签（属性5）
        QLabel *label6 = new QLabel("请输入属性5：");
        input6 = new QLineEdit();
        layout->addWidget(label6);
        layout->addWidget(input6);

        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &AddKindDialog::accept);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }
    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }
    // 获取第三个输入框内容
    QString getInput3() const { return input3->text(); }
    // 获取第四个输入框内容
    QString getInput4() const { return input4->text(); }
    // 获取第五个输入框内容
    QString getInput5() const { return input5->text(); }
    // 获取第六个输入框内容
    QString getInput6() const { return input6->text(); }


private:
    QLineEdit *input1;  // 类型名输入框
    QLineEdit *input2;  // 属性1输入框
    QLineEdit *input3;  // 属性2确认框
    QLineEdit *input4;  // 属性3输入框
    QLineEdit *input5;  // 属性4输入框
    QLineEdit *input6;  // 属性5输入框
};


class reviseKindDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    reviseKindDialog(QWidget *parent = nullptr,QString s2="默认属性1",QString s3="默认属性2"
                     ,QString s4="默认属性1",QString s5="默认属性1",QString s6="默认属性1") : QDialog(parent) {
        setWindowTitle("管理员-添加物品类型");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 400);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);


        // 创建第二个输入框和标签（属性1）
        QLabel *label2 = new QLabel("请输入属性1：");
        input2 = new QLineEdit();
        input2->setText(s2);        // 设置默认属性1
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建第三个输入框和标签（属性2）
        QLabel *label3 = new QLabel("请输入属性2：");
        input3 = new QLineEdit();
        input3->setText(s3);        // 设置默认属性2
        layout->addWidget(label3);
        layout->addWidget(input3);

        // 创建第四个输入框和标签（属性3）
        QLabel *label4 = new QLabel("请输入属性3：");
        input4 = new QLineEdit();
        input4->setText(s4);        // 设置默认属性3
        layout->addWidget(label4);
        layout->addWidget(input4);

        // 创建第五个输入框和标签（属性4）
        QLabel *label5 = new QLabel("请输入属性4：");
        input5 = new QLineEdit();
        input5->setText(s5);        // 设置默认属性4
        layout->addWidget(label5);
        layout->addWidget(input5);

        // 创建第六个输入框和标签（属性5）
        QLabel *label6 = new QLabel("请输入属性5：");
        input6 = new QLineEdit();
        input6->setText(s6);        // 设置默认属性5
        layout->addWidget(label6);
        layout->addWidget(input6);

        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &reviseKindDialog::accept);
    }


    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }
    // 获取第三个输入框内容
    QString getInput3() const { return input3->text(); }
    // 获取第四个输入框内容
    QString getInput4() const { return input4->text(); }
    // 获取第五个输入框内容
    QString getInput5() const { return input5->text(); }
    // 获取第六个输入框内容
    QString getInput6() const { return input6->text(); }



private:
    QLineEdit *input2;  // 属性1输入框
    QLineEdit *input3;  // 属性2确认框
    QLineEdit *input4;  // 属性3输入框
    QLineEdit *input5;  // 属性4输入框
    QLineEdit *input6;  // 属性5输入框

};

// 登陆输入对话框类，继承自QDialog
class LoginDialog : public QDialog {
    Q_OBJECT  // Qt宏，启用元对象系统（信号槽机制）
public:
    // 构造函数，初始化对话框界面
    LoginDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("物品复活软件");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 150);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建第一个输入框和标签（用户名输入）
        QLabel *label1 = new QLabel("用户名：");
        input1 = new QLineEdit();
        layout->addWidget(label1);
        layout->addWidget(input1);

        // 创建第二个输入框和标签（密码输入）
        QLabel *label2 = new QLabel("密码：");
        input2 = new QLineEdit();
        input2->setEchoMode(QLineEdit::Password);//隐藏密码输入
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建按钮水平布局
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        // 创建注册按钮
        QPushButton *registerButton;  // 注册按钮
        registerButton = new QPushButton("没有账号？立即注册");
        registerButton->setStyleSheet("QPushButton {"
                                      "   font-size: 10px;"
                                      "   color: blue;"
                                      "   background-color: transparent;"
                                      "   border: none;"
                                      "   text-decoration: underline;"
                                      "}"
                                      "QPushButton:hover {"
                                      "   color: darkblue;"
                                      "}");
        buttonLayout->addWidget(registerButton);
        buttonLayout->addStretch();  // 添加弹性空间
        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        buttonLayout->addWidget(okButton);

        layout->addLayout(buttonLayout);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &LoginDialog::accept);
        connect(registerButton, &QPushButton::clicked, this, &LoginDialog::Register);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }
    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }

private:
    QLineEdit *input1;  // 用户名输入框
    QLineEdit *input2;  // 密码输入框

private slots:
    void Register()
    {
        RegisterDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            // 如果用户点击确定，获取输入内容

            //判断用户名是否为空
            QString input1 = dialog.getInput1();
            if(input1.isEmpty())
            {
                QMessageBox::information(this, "错误", "用户名不能为空", QMessageBox::Ok);
                return;
            }

            //判断密码是否为空
            QString input2 = dialog.getInput2();//密码
            if(input2.isEmpty())
            {
                QMessageBox::information(this, "错误", "密码不能为空", QMessageBox::Ok);
                return;
            }

            //判断确认密码是否为空
            QString input3 = dialog.getInput3();//确认密码
            if(input3.isEmpty())
            {
                QMessageBox::information(this, "错误", "请确认密码", QMessageBox::Ok);
                return;
            }
            QString input4 = dialog.getInput4();//用户住址
            QString input5 = dialog.getInput5();//用户联系电话
            QString input6 = dialog.getInput6();//用户联系邮箱

            //转换为string类，以便后续存储
            string s11 = qstr2std( input1 );
            string s12 = qstr2std( input2 );
            string s13 = qstr2std( input3 );
            string s14 = qstr2std( input4 );
            string s15 = qstr2std( input5 );
            string s16 = qstr2std( input6 );

            int z=0;         //判定账号是否已经存在，0为不存在，1为存在
            Account a1;      //创建账户类对象
            string s;        //读取文件第一行

            //读取文件各部分内容
            string s1;
            string s2;
            string s3;
            string s4;
            string s5;
            string s6;


            if(a1.Add(s11,s12,s13,s14,s15,s16))
            {
                //查询账号是否已经存在
                ifstream inputFile("account.txt");
                if (!inputFile.is_open())
                {
                    qDebug() << "无法打开文件 account.txt，数据读入失败\n" ;
                }
                getline(inputFile, s,'\n');//去除文件中第一行
                int L=stringToInt(s);//目前账号数

                while (getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                       &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\n'))
                {
                    if((s1==a1.Return_a()))
                    {
                        QMessageBox::information(this, "提示", "该账号已经存在，请更换账号名重新注册", QMessageBox::Ok);
                        z=1;
                        break;
                    }
                }
                //注册成功
                if(z==0)
                {
                    a1.Writefile("account.txt");                //写入文件
                    replaceFirstLine("account.txt",L+1);        //用户数目+1
                    QMessageBox::information(this, "提示", "注册成功，请等待管理员审核", QMessageBox::Ok);
                }
            }
            else
            {
                //密码长度不符合要求或两次输入密码不一致
                QMessageBox::critical(
                    nullptr,
                    "错误",
                    "密码长度太长或两次输入密码不一致！请重试！",
                    QMessageBox::Ok
                    );
            }
        }

    }

};

// 添加物品输入对话框类，继承自QDialog
class AddObjectDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    AddObjectDialog(int a=5,QWidget *parent = nullptr,QString q4="",QString q5="",QString q6="",QString q7="",QString q8="") : QDialog(parent) {
        setWindowTitle("普通用户-添加物品");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 400+60*a);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建第一部分：物品公共信息标签
        QLabel *label0 = new QLabel("请输入物品公共的信息：");
        layout->addWidget(label0);

        // 创建第一个输入框和标签（物品名称）
        QLabel *label1 = new QLabel("请输入物品名称：");
        input1 = new QLineEdit();
        layout->addWidget(label1);
        layout->addWidget(input1);

        // 创建第二个输入框和标签（物品说明）
        QLabel *label2 = new QLabel("请输入物品说明：");
        input2 = new QLineEdit();
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建第三个输入框和标签（物品所在地址）
        QLabel *label3 = new QLabel("请输入物品所在地址：");
        input3 = new QLineEdit();
        layout->addWidget(label3);
        layout->addWidget(input3);

        // 创建第四个输入框和标签（联系人手机）
        QLabel *label4 = new QLabel("请输入联系人手机号：");
        input4 = new QLineEdit();
        layout->addWidget(label4);
        layout->addWidget(input4);

        // 创建第五个输入框和标签（联系人邮箱）
        QLabel *label5 = new QLabel("请输入联系人邮箱：");
        input5 = new QLineEdit();
        layout->addWidget(label5);
        layout->addWidget(input5);

        // 创建第二部分：物品类别信息标签
        QLabel *label20 = new QLabel("请输入物品类别的信息：");
        layout->addWidget(label20);

        // 创建第六个输入框和标签(属性1)
        QLabel *label6 = new QLabel("请输入 " + q4 + "：");
        input6 = new QLineEdit();
        layout->addWidget(label6);
        layout->addWidget(input6);

        //该类型无属性1
        if (a < 1) {
            label6->setVisible(false);
            input6->setVisible(false);
        } else {
            label6->setVisible(true);
            input6->setVisible(true);
        }

        // 创建第七个输入框和标签(属性2)
        QLabel *label7 = new QLabel("请输入 " + q5 + "：");
        input7 = new QLineEdit();
        layout->addWidget(label7);
        layout->addWidget(input7);

        //该类型无属性2
        if (a < 2) {
            label7->setVisible(false);
            input7->setVisible(false);
        } else {
            label7->setVisible(true);
            input7->setVisible(true);
        }
        // 创建第八个输入框和标签(属性3)
        QLabel *label8 = new QLabel("请输入 " + q6 + "：");
        input8 = new QLineEdit();
        layout->addWidget(label8);
        layout->addWidget(input8);

        //该类型无属性3
        if (a < 3) {
            label8->setVisible(false);
            input8->setVisible(false);
        } else {
            label8->setVisible(true);
            input8->setVisible(true);
        }

        // 创建第九个输入框和标签(属性4)
        QLabel *label9 = new QLabel("请输入 " + q7 + "：");
        input9 = new QLineEdit();
        layout->addWidget(label9);
        layout->addWidget(input9);

        //该类型无属性4
        if (a < 4) {
            label9->setVisible(false);
            input9->setVisible(false);
        } else {
            label9->setVisible(true);
            input9->setVisible(true);
        }

        // 创建第十个输入框和标签(属性5)
        QLabel *label10 = new QLabel("请输入 " + q8 + "：");
        input10 = new QLineEdit();
        layout->addWidget(label10);
        layout->addWidget(input10);

        //该类型无属性5
        if (a < 5) {
            label10->setVisible(false);
            input10->setVisible(false);
        } else {
            label10->setVisible(true);
            input10->setVisible(true);
        }
        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &AddKindDialog::accept);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }
    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }
    // 获取第三个输入框内容
    QString getInput3() const { return input3->text(); }
    // 获取第四个输入框内容
    QString getInput4() const { return input4->text(); }
    // 获取第五个输入框内容
    QString getInput5() const { return input5->text(); }
    // 获取第六个输入框内容
    QString getInput6() const { return input6->text(); }
    // 获取第七个输入框内容
    QString getInput7() const { return input7->text(); }
    // 获取第八个输入框内容
    QString getInput8() const { return input8->text(); }
    // 获取第九个输入框内容
    QString getInput9() const { return input9->text(); }
    // 获取第十个输入框内容
    QString getInput10() const { return input10->text(); }

private:
    QLineEdit *input1;  // 物品名称输入框
    QLineEdit *input2;  // 物品说明输入框
    QLineEdit *input3;  // 物品地址确认框
    QLineEdit *input4;  // 联系人手机输入框
    QLineEdit *input5;  // 联系人邮箱输入框
    QLineEdit *input6;  // 属性1输入框
    QLineEdit *input7;  // 属性2确认框
    QLineEdit *input8;  // 属性3输入框
    QLineEdit *input9;  // 属性4输入框
    QLineEdit *input10;  // 属性5输入框

};

class ReviseObjectDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    ReviseObjectDialog(QWidget *parent = nullptr,QString q0="其它",QString q1="",QString q2="",QString q3="",QString q4=""
                       ,QString q5="",QString q6="",QString q7="",QString q8="",QString q9="",QString q10="") : QDialog(parent) {

        qk=q0;        //赋物品类型值


        setWindowTitle("普通用户-修改物品");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 400+60*a);  // 固定对话框大小


        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);
        //类型选择框
        QComboBox *comboBox = new QComboBox();
        qDebug() << qk ;
        layout->addWidget(comboBox);
        string s;
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;
        ifstream inputFile("kinds.txt");
        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//读取第一行物品数

        int num = stringToInt(s);//保存第一行物品数
        QTableWidget *table = new QTableWidget(num, 7);  // 创建num行7列的表格
        int i=0;
        while (  getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\n'))

        {
            // 读取类型
            QString q21 = std2qstr(s1);
            QString q22 = std2qstr(s2);
            QString q23 = std2qstr(s3);
            QString q24 = std2qstr(s4);
            QString q25 = std2qstr(s5);
            QString q26 = std2qstr(s6);
            QString q27 = std2qstr(s7);

            //将读取的类型名加入选框中
            comboBox->addItem(QString(q21).arg(i+1));

            //将读取的其余信息保存在表格中
            table->setItem(i, 0, new QTableWidgetItem(q21));
            table->setItem(i, 1, new QTableWidgetItem(q22));
            table->setItem(i, 2, new QTableWidgetItem(q23));
            table->setItem(i, 3, new QTableWidgetItem(q24));
            table->setItem(i, 4, new QTableWidgetItem(q25));
            table->setItem(i, 5, new QTableWidgetItem(q26));
            table->setItem(i, 6, new QTableWidgetItem(q27));

            if(q21==q0)
            {
                a= stringToInt(s2);
                setFixedSize(300, 400+60*a);  // 动态调整对话框大小
                //赋属性值
                q11=q23;
                q12=q24;
                q13=q25;
                q14=q26;
                q15=q27;
            }
            i++;

        }
        comboBox->setCurrentText(qk);//设置默认值为原类型
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                [this, comboBox, table](int index) {

                    // 获取新类型的信息（从选框中获取）
                    qk = comboBox->itemText(index);

                    // 获取该类型属性信息
                    q11 = table->item(index, 2)->text();
                    q12 = table->item(index, 3)->text();
                    q13 = table->item(index, 4)->text();
                    q14 = table->item(index, 5)->text();
                    q15 = table->item(index, 6)->text();

                    //获取该类型有效属性数
                    QString qnum = table->item(index, 1)->text();
                    string snum = qstr2std(qnum);
                    a = stringToInt(snum);

                    // 更新标签文本

                    //该类型有属性1
                    if (a >= 1) {
                        label6->setText("请输入 " + q11 + "：");
                        label6->setVisible(true);
                        input6->setVisible(true);
                    } else {
                        label6->setVisible(false);
                        input6->setVisible(false);
                    }

                    //该类型有属性2
                    if (a >= 2) {
                        label7->setText("请输入 " + q12 + "：");
                        label7->setVisible(true);
                        input7->setVisible(true);
                    } else {
                        label7->setVisible(false);
                        input7->setVisible(false);
                    }

                    //该类型有属性3
                    if (a >= 3) {
                        label8->setText("请输入 " + q13 + "：");
                        label8->setVisible(true);
                        input8->setVisible(true);
                    } else {
                        label8->setVisible(false);
                        input8->setVisible(false);
                    }

                    //该类型有属性4
                    if (a >= 4) {
                        label9->setText("请输入 " + q14 + "：");
                        label9->setVisible(true);
                        input9->setVisible(true);
                    } else {
                        label9->setVisible(false);
                        input9->setVisible(false);
                    }

                    //该类型有属性5
                    if (a >= 5) {
                        label10->setText("请输入 " + q15 + "：");
                        label10->setVisible(true);
                        input10->setVisible(true);
                    } else {
                        label10->setVisible(false);
                        input10->setVisible(false);
                    }

                    // 调整对话框大小
                    setFixedSize(300, 400 + 60 * a);
                });


        // 创建第一部分：物品公共信息标签
        QLabel *label0 = new QLabel("请输入物品公共的信息：");
        layout->addWidget(label0);

        // 创建第一个输入框和标签（物品名称）
        QLabel *label1 = new QLabel("请输入物品名称：");
        input1 = new QLineEdit();
        input1->setText(q1);        // 设置默认物品名称
        layout->addWidget(label1);
        layout->addWidget(input1);

        // 创建第二个输入框和标签（物品说明）
        QLabel *label2 = new QLabel("请输入物品说明：");
        input2 = new QLineEdit();
        input2->setText(q2);        // 设置默认物品说明
        layout->addWidget(label2);
        layout->addWidget(input2);

        // 创建第三个输入框和标签（物品所在地址）
        QLabel *label3 = new QLabel("请输入物品所在地址：");
        input3 = new QLineEdit();
        input3->setText(q3);        // 设置默认物品所在地址
        layout->addWidget(label3);
        layout->addWidget(input3);

        // 创建第四个输入框和标签（联系人手机号）
        QLabel *label4 = new QLabel("请输入联系人手机号：");
        input4 = new QLineEdit();
        input4->setText(q4);        // 设置默认联系人手机号
        layout->addWidget(label4);
        layout->addWidget(input4);

        // 创建第五个输入框和标签（联系人邮箱）
        QLabel *label5 = new QLabel("请输入联系人邮箱：");
        input5 = new QLineEdit();
        input5->setText(q5);        // 设置默认联系人邮箱
        layout->addWidget(label5);
        layout->addWidget(input5);

        // 创建第二部分：物品类别信息标签（物品类别的信息）
        QLabel *label20 = new QLabel("请输入物品类别的信息：");
        layout->addWidget(label20);

        // 创建第六个输入框和标签(属性1)
        label6 = new QLabel("请输入 " + q11 + "：");
        input6 = new QLineEdit();
        input6->setText(q6);        // 设置默认属性1
        layout->addWidget(label6);
        layout->addWidget(input6);

        //该类型无属性1
        if (a < 1) {
            label6->setVisible(false);
            input6->setVisible(false);
        } else {
            label6->setVisible(true);
            input6->setVisible(true);
        }

        // 创建第七个输入框和标签(属性2)
        label7 = new QLabel("请输入 " + q12 + "：");
        input7 = new QLineEdit();
        input7->setText(q7);        // 设置默认属性2
        layout->addWidget(label7);
        layout->addWidget(input7);

        //该类型无属性2
        if (a < 2) {
            label7->setVisible(false);
            input7->setVisible(false);
        } else {
            label7->setVisible(true);
            input7->setVisible(true);
        }
        // 创建第八个输入框和标签(属性3)
        label8 = new QLabel("请输入 " + q13 + "：");
        input8 = new QLineEdit();
        input8->setText(q8);        // 设置默认属性3
        layout->addWidget(label8);
        layout->addWidget(input8);

        //该类型无属性3
        if (a < 3) {
            label8->setVisible(false);
            input8->setVisible(false);
        } else {
            label8->setVisible(true);
            input8->setVisible(true);
        }

        // 创建第九个输入框和标签(属性4)
        label9 = new QLabel("请输入 " + q14 + "：");
        input9 = new QLineEdit();
        input9->setText(q9);        // 设置默认属性4
        layout->addWidget(label9);
        layout->addWidget(input9);

        //该类型无属性4
        if (a < 4) {
            label9->setVisible(false);
            input9->setVisible(false);
        } else {
            label9->setVisible(true);
            input9->setVisible(true);
        }

        // 创建第十个输入框和标签(属性5)
        label10 = new QLabel("请输入 " + q15 + "：");
        input10 = new QLineEdit();
        input10->setText(q10);        // 设置默认属性5
        layout->addWidget(label10);
        layout->addWidget(input10);

        //该类型无属性5
        if (a < 5) {
            label10->setVisible(false);
            input10->setVisible(false);
        } else {
            label10->setVisible(true);
            input10->setVisible(true);
        }
        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &AddKindDialog::accept);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }
    // 获取第二个输入框内容
    QString getInput2() const { return input2->text(); }
    // 获取第三个输入框内容
    QString getInput3() const { return input3->text(); }
    // 获取第四个输入框内容
    QString getInput4() const { return input4->text(); }
    // 获取第五个输入框内容
    QString getInput5() const { return input5->text(); }
    // 获取第六个输入框内容
    QString getInput6() const { return input6->text(); }
    // 获取第七个输入框内容
    QString getInput7() const { return input7->text(); }
    // 获取第八个输入框内容
    QString getInput8() const { return input8->text(); }
    // 获取第九个输入框内容
    QString getInput9() const { return input9->text(); }
    // 获取第十个输入框内容
    QString getInput10() const { return input10->text(); }
    // 获取物品类型
    QString getKind() const { return qk; }

private:
    QLabel *label6;     // 属性1名称标签
    QLabel *label7;     // 属性2名称标签
    QLabel *label8;     // 属性3名称标签
    QLabel *label9;     // 属性4名称标签
    QLabel *label10;    // 属性5名称标签
    QLineEdit *input1;  // 物品名称输入框
    QLineEdit *input2;  // 物品说明输入框
    QLineEdit *input3;  // 物品地址确认框
    QLineEdit *input4;  // 联系人手机输入框
    QLineEdit *input5;  // 联系人邮箱输入框
    QLineEdit *input6;  // 属性1输入框
    QLineEdit *input7;  // 属性2确认框
    QLineEdit *input8;  // 属性3输入框
    QLineEdit *input9;  // 属性4输入框
    QLineEdit *input10;  // 属性5输入框
    QString qk;//保存最终选择的类型名
    QString q11="属性1";
    QString q12="属性2";
    QString q13="属性3";
    QString q14="属性4";
    QString q15="属性5";  //保存选择类型的5个属性
    int a=0;             //非空属性数
};


// 物品搜索输入类，继承自QDialog
class SearchObjectDialog : public QDialog {
public:
    // 构造函数，初始化对话框界面
    SearchObjectDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("物品复活软件-搜索物品");  // 设置窗口标题
        setModal(true);  // 设置为模态对话框，阻塞父窗口
        setFixedSize(300, 100);  // 固定对话框大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);

        // 创建一个输入框和标签（搜索内容）
        QLabel *label1 = new QLabel("请输入搜索内容：");
        input1 = new QLineEdit();
        layout->addWidget(label1);
        layout->addWidget(input1);


        // 创建确定按钮
        QPushButton *okButton = new QPushButton("确定");
        layout->addWidget(okButton);

        // 连接按钮点击信号到对话框的accept槽
        connect(okButton, &QPushButton::clicked, this, &RegisterDialog::accept);
    }

    // 获取第一个输入框内容
    QString getInput1() const { return input1->text(); }



private:
    QLineEdit *input1;  // 搜索内容输入框

};

// 第二窗口类，继承自QWidget
class SecondWindow : public QWidget {
    Q_OBJECT
public:
    SecondWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("物品复活软件");  // 设置窗口标题
        setFixedSize(800, 400);  // 固定窗口大小
        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);
        setLayout(layout);  // 关键：设置布局

        // 添加物品按钮
        QPushButton *Button1 = new QPushButton("添加物品");
        Button1->setFixedWidth(200);
        Button1->setFixedHeight(50);
        layout->addWidget(Button1);  // 添加到布局

        // 显示你的物品按钮
        QPushButton *Button2 = new QPushButton("修改你的物品");
        Button2->setFixedWidth(200);
        Button2->setFixedHeight(50);
        layout->addWidget(Button2);  // 添加到布局

        // 搜索物品
        QPushButton *Button5 = new QPushButton("搜索物品");
        Button5->setFixedWidth(200);
        Button5->setFixedHeight(50);
        layout->addWidget(Button5);  // 添加到布局

        // 关闭应用
        QPushButton *Button6 = new QPushButton("关闭应用");
        Button6->setFixedWidth(200);
        Button6->setFixedHeight(50);
        layout->addWidget(Button6);  // 添加到布局
        setLayout(layout);
        layout->setAlignment(Qt::AlignCenter);


        // 连接信号槽
        connect(Button1, &QPushButton::clicked, this, &SecondWindow::addobject);
        connect(Button2, &QPushButton::clicked, this, &SecondWindow::showMyObject);
        connect(Button5, &QPushButton::clicked, this, &SecondWindow::SearchObject);
        connect(Button6, &QPushButton::clicked, this, &SecondWindow::close);
    }

private slots:

    //搜索物品函数
    void SearchObject() {
        string s;  //去除保存行数的第一行

        //保存文件存储的13个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;
        string s8;
        string s9;
        string s10;
        string s11;
        string s12;
        string s13;

        //读取物品文件
        ifstream inputFile("data.txt");

        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//去除保存行数的一行

        int num = stringToInt(s);//保存表格行数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存


        QTableWidget *table = new QTableWidget(num, 13);  // 新建表格
        QLabel *label1 = new QLabel("");
        QComboBox *comboBox = new QComboBox();
        string ss; //去除保存行数的第一行

        //保存文件存储的7个部分的信息
        string ss1;
        string ss2;
        string ss3;
        string ss4;
        string ss5;
        string ss6;
        string ss7;

        //读取类型文件
        ifstream inputFile2("kinds.txt");
        if (!inputFile2.is_open())

        {

            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

        }

        getline(inputFile2, ss,'\n');//读取第一行物品数

        int j=0;
        while (  getline(inputFile2, ss1,'\t')&&getline(inputFile2, ss2,'\t')&&getline(inputFile2, ss3,'\t')
               &&getline(inputFile2, ss4,'\t')&&getline(inputFile2, ss5,'\t')&&getline(inputFile2, ss6,'\t')
               &&getline(inputFile2, ss7,'\n'))

        {
            // 设置选框内容
            QString q21 = std2qstr(ss1);
            comboBox->addItem(QString(q21).arg(j+1));
            j++;
        }

        connect(comboBox, QOverload<int>::of(&QComboBox::activated),
                [this, comboBox, table,label1](int index) {
                    // 初始化可见行计数器
                    int visibleRowCount = 0;

                    // 处理无效索引（-1表示无选择）
                    if (index == -1) {
                        // 显示所有行（重置筛选）
                        for (int row = 0; row < table->rowCount(); ++row) {
                            table->setRowHidden(row, false);
                        }
                        visibleRowCount = table->rowCount();
                        int a = visibleRowCount;

                        // 设置标签文本：显示可见行数
                        label1->setText(QString::number(a));
                        return;
                    }

                    // 获取当前选中项的文本
                    QString selectedText = comboBox->currentText();

                    bool shouldShow;
                    // 遍历表格所有行
                    for (int row = 0; row < table->rowCount(); ++row) {
                        // 获取第一列（列索引0）的单元格
                        QTableWidgetItem* item = table->item(row, 0);

                        // 检查单元格是否存在且文本匹配
                        shouldShow = item && (item->text() == selectedText);
                        table->setRowHidden(row, !shouldShow);

                        // 如果该行可见，增加计数器
                        if (shouldShow) {
                            visibleRowCount++;
                        }
                    }

                    // 将可见行数保存在变量a中
                    int a = visibleRowCount;

                    // 设置标签文本：显示可见行数
                    label1->setText("该类型共有"+QString::number(a)+"个物品");

                    //弹出搜索框
                    this->showMinimized();
                    SearchObjectDialog dialog(this);


                    if (dialog.exec() == QDialog::Accepted) {
                        // 如果用户点击确定，获取输入内容
                        QString input1 = dialog.getInput1();
                        int visibleRowCount=0;
                        for (int row = 0; row < table->rowCount(); ++row) {
                            // 获取第一列（列索引0）的单元格
                            QTableWidgetItem* item1 = table->item(row, 1);
                            QTableWidgetItem* item3 = table->item(row, 3);
                            QTableWidgetItem* item5 = table->item(row, 5);
                            QTableWidgetItem* item =  table->item(row, 0);

                            //检查单元格是否包含搜索的文本以及是不是所选择的类型
                            bool shouldShow2 = ((item1->text().contains(input1, Qt::CaseSensitive))
                                                ||(item3->text().contains(input1, Qt::CaseSensitive))
                                                ||(item5->text().contains(input1, Qt::CaseSensitive)))&&(item->text() == selectedText);

                            // 不包含搜索文本的行隐藏
                            table->setRowHidden(row, !shouldShow2);

                            // 如果该行可见，增加计数器
                            if (shouldShow2) {
                                visibleRowCount++;
                            }
                        }
                        int a = visibleRowCount;
                        label1->setText("共搜索到"+QString::number(a)+"个物品");
                    }

                });


        //表格后8行不可见，仅保存数据
        for (int col = 5; col < 13; ++col)
        {
            table->setColumnHidden(col, true);
        }

        table->setHorizontalHeaderLabels({"物品类型","物品名称","物品所在地址","添加用户","查看详细信息"});

        table->verticalHeader()->setVisible(false);

        int i=0;
        while (  getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\t')&&getline(inputFile, s8,'\t')&&getline(inputFile, s9,'\t')
               &&getline(inputFile, s10,'\t')&&getline(inputFile, s11,'\t')&&getline(inputFile, s12,'\t')
               &&getline(inputFile, s13,'\n'))
        {
            //不是审核通过状态，不展示
            if(s13!="1")
            {
                continue;
            }

            QString q1 = std2qstr(s1);//物品类型
            QString q2 = std2qstr(s2);//物品名称
            QString q3 = std2qstr(s4);//物品所在地址
            QString q4 = std2qstr(s5);;//添加用户
            QString q8 = std2qstr(s3);//物品说明
            QString q9 = std2qstr(s6);//联系人手机
            QString q10 = std2qstr(s7);//联系人邮箱
            QString q11 = std2qstr(s8);//属性1
            QString q12 = std2qstr(s9);//属性2
            QString q13 = std2qstr(s10);//属性3
            QString q14 = std2qstr(s11);//属性4
            QString q15 = std2qstr(s12);//属性5

            //把数据存在表格中
            table->setItem(i, 0, new QTableWidgetItem(q1));
            table->setItem(i, 1, new QTableWidgetItem(q2));
            table->setItem(i, 2, new QTableWidgetItem(q3));
            table->setItem(i, 3, new QTableWidgetItem(q4));
            table->setItem(i, 5, new QTableWidgetItem(q8));
            table->setItem(i, 6, new QTableWidgetItem(q9));
            table->setItem(i, 7, new QTableWidgetItem(q10));
            table->setItem(i, 8, new QTableWidgetItem(q11));
            table->setItem(i, 9, new QTableWidgetItem(q12));
            table->setItem(i, 10, new QTableWidgetItem(q13));
            table->setItem(i, 11, new QTableWidgetItem(q14));
            table->setItem(i, 12, new QTableWidgetItem(q15));

            //查看详细信息按钮
            QPushButton *button0 = new QPushButton("查看详细信息");
            table->setCellWidget(i, 4, button0);

            connect(button0, &QPushButton::clicked, [this,table, i]() {

                string s;  //读取第一行类型数专用

                //保存文件读出的7个部分数据
                string s1; //物品类型名（文件读出）
                string s2;
                string s3;
                string s4;
                string s5;
                string s6;
                string s7;

                QString q41 = table->item(i, 0)->text();//物品类型名（表中读出）

                //读取类型文件
                ifstream inputFile("kinds.txt");
                if (!inputFile.is_open())

                {

                    qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

                }

                getline(inputFile, s,'\n');//读取第一行类型数

                while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                       &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

                {
                    if(q41==std2qstr(s1))
                        break;

                }
                //转换为 QString类对象
                QString q61=std2qstr(s3);
                QString q62=std2qstr(s4);
                QString q63=std2qstr(s5);
                QString q64=std2qstr(s6);
                QString q65=std2qstr(s7);


                QWidget *window2 = new QWidget;                  // 新建窗口
                window2->setAttribute(Qt::WA_DeleteOnClose);     // 关闭时自动释放内存
                QTableWidget *table2 = new QTableWidget(8, 1);   //新建表格
                table2->setHorizontalHeaderLabels({"物品详细信息"});
                table2->setVerticalHeaderLabels(QStringList{"联系人手机", "联系人邮箱", q61, q62,q63,q64,q65,"物品说明"});
                QString q51 = table->item(i, 6)->text();//联系人手机
                QString q52 = table->item(i, 7)->text();//联系人邮箱
                QString q53 = table->item(i, 8)->text();//属性1
                QString q54 = table->item(i, 9)->text();//属性2
                QString q55 = table->item(i, 10)->text();//属性3
                QString q56 = table->item(i, 11)->text();//属性4
                QString q57 = table->item(i, 12)->text();//属性5
                QString q58 = table->item(i, 5)->text();//物品说明
                table2->setItem(0, 0, new QTableWidgetItem(q51));
                table2->setItem(1, 0, new QTableWidgetItem(q52));

                //判断有无属性1
                if (!q61.isEmpty()) {
                    table2->setItem(2, 0, new QTableWidgetItem(q53));
                } else {
                    table2->setRowHidden(2, true); // 隐藏第三行
                }

                //判断有无属性2
                if (!q62.isEmpty()) {
                    table2->setItem(3, 0, new QTableWidgetItem(q54));
                } else {
                    table2->setRowHidden(3, true); // 隐藏第四行
                }

                //判断有无属性3
                if (!q63.isEmpty()) {
                    table2->setItem(4, 0, new QTableWidgetItem(q55));
                } else {
                    table2->setRowHidden(4, true); // 隐藏第五行
                }

                //判断有无属性4
                if (!q64.isEmpty()) {
                    table2->setItem(5, 0, new QTableWidgetItem(q56));
                } else {
                    table2->setRowHidden(5, true); // 隐藏第六行
                }

                //判断有无属性5
                if (!q65.isEmpty()) {
                    table2->setItem(6, 0, new QTableWidgetItem(q57));
                } else {
                    table2->setRowHidden(6, true); // 隐藏第七行
                }

                //物品说明从左侧顶部开始写
                QTableWidgetItem *item = new QTableWidgetItem(q58);
                item->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                item->setFlags(item->flags() | Qt::ItemIsEditable);
                table2->setItem(7, 0, item);


                table2->setColumnWidth(0, 400);  // 第一列宽度设为400像素
                table2->setRowHeight(7, 200); // 第八行高度设为400像素
                QHBoxLayout *layout3 = new QHBoxLayout;

                //布局加入表格
                layout3->addWidget(table2);

                //界面展示布局，并设置名称、大小
                window2->setLayout(layout3);
                window2->setWindowTitle("详细信息");
                window2->resize(500, 600);
                window2->show();

            });
            i++;
        }
        table->setRowCount(i);   //表格重设行数
        label1->setText("目前一共有" + QString::number(i) + "个物品");
        label1->setFixedWidth(120);
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入标签、选框、表格
        layout2->addWidget(label1);
        layout2->addWidget(comboBox);
        layout2->addWidget(table);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("搜索物品表格");
        window->resize(900, 600);
        window->show();
    }
    void ShowAddObjectDialog(int L,QString kind,int a,QString q4,QString q5,QString q6,QString q7,QString q8)
    {
        AddObjectDialog dialog(a,this,q4,q5,q6,q7,q8);  // 创建对话框实例
        // 显示对话框并等待用户操作
        if (dialog.exec() == QDialog::Accepted) {
            // 如果用户点击确定，获取输入内容
            QString input1 = dialog.getInput1();

            //物品名称为空
            if(input1.isEmpty())
            {
                qDebug() << "物品名称为空！" ;
                QMessageBox::information(this, "提示", "不能添加名称为空的物品！", QMessageBox::Ok);
                return;
            }

            QString input2 = dialog.getInput2();
            QString input3 = dialog.getInput3();
            QString input4 = dialog.getInput4();
            QString input5 = dialog.getInput5();
            QString input6 = dialog.getInput6();
            QString input7 = dialog.getInput7();
            QString input8 = dialog.getInput8();
            QString input9 = dialog.getInput9();
            QString input10 = dialog.getInput10();

            //Qstring转为string，以便后续写入文件
            string k = qstr2std(kind);
            string s11 = qstr2std(input1);
            string s12 = qstr2std(input2);
            string s13 = qstr2std(input3);
            string s14 = qstr2std(input4);
            string s15 = qstr2std(input5);
            string s16 = qstr2std(input6);
            string s17 = qstr2std(input7);
            string s18 = qstr2std(input8);
            string s19 = qstr2std(input9);
            string s20 = qstr2std(input10);

            // 在控制台输出用户输入（调试用）
            qDebug() << "输入 物品类型:" << k.c_str()
                     << "物品名称:" << s11.c_str()
                     << "\n物品说明:" << s12.c_str()
                     << "\n物品地址:" << s13.c_str()
                     << "\n用户账号" << ID.c_str()
                     << "\n联系人手机" << s14.c_str()
                     << "\n联系人邮箱" << s15.c_str()
                     << "\n属性1" << s16.c_str()
                     << "\n属性2" << s17.c_str()
                     << "\n属性3" << s18.c_str()
                     << "\n属性4" << s19.c_str()
                     << "\n属性5" << s20.c_str();

            object object1;//创建物品类对象
            if(object1.Add(k,s11,s12,s13,ID,s14,s15,s16,s17,s18,s19,s20))
            {
                object1.Writefile("data.txt");        //写入文件
                replaceFirstLine("data.txt",L+1);     //文件首行物品数+1
                QMessageBox::information(this, "提示", "添加物品成功", QMessageBox::Ok);
            }
        }
    }

    void ShowReviseObjectDialog(QString q0,QString q1,QString q2,QString q3,QString q4,QString q5
                                ,QString q6,QString q7,QString q8,QString q9,QString q10,int i)
    {
        ReviseObjectDialog dialog(this,q0,q1,q3,q2,q4,q5,q6,q7,q8,q9,q10);

        if (dialog.exec() == QDialog::Accepted) {
            // 如果用户点击确定，获取输入内容
            QString kind = dialog.getKind();
            QString input1 = dialog.getInput1();
            if(input1.isEmpty())
            {
                qDebug() << "物品名称为空！" ;
                QMessageBox::information(this, "提示", "不能将物品名称修改为空！", QMessageBox::Ok);
                return;
            }
            QString input2 = dialog.getInput2();
            QString input3 = dialog.getInput3();
            QString input4 = dialog.getInput4();
            QString input5 = dialog.getInput5();
            QString input6 = dialog.getInput6();
            QString input7 = dialog.getInput7();
            QString input8 = dialog.getInput8();
            QString input9 = dialog.getInput9();
            QString input10 = dialog.getInput10();

            //Qstring转为string，以便后续写入文件
            string k = qstr2std(kind);
            string s11 = qstr2std(input1);
            string s12 = qstr2std(input2);
            string s13 = qstr2std(input3);
            string s14 = qstr2std(input4);
            string s15 = qstr2std(input5);
            string s16 = qstr2std(input6);
            string s17 = qstr2std(input7);
            string s18 = qstr2std(input8);
            string s19 = qstr2std(input9);
            string s20 = qstr2std(input10);

            // 在控制台输出用户输入（调试用）
            qDebug() << "输入 物品类型:" << k.c_str()
                     << "物品名称:" << s11.c_str()
                     << "\n物品说明:" << s12.c_str()
                     << "\n物品地址:" << s13.c_str()
                     << "\n用户账号" << ID.c_str()
                     << "\n联系人手机" << s14.c_str()
                     << "\n联系人邮箱" << s15.c_str()
                     << "\n属性1" << s16.c_str()
                     << "\n属性2" << s17.c_str()
                     << "\n属性3" << s18.c_str()
                     << "\n属性4" << s19.c_str()
                     << "\n属性5" << s20.c_str();


            //删除老物品
            // 打开文件读取
            ifstream inFile("data.txt");
            if (!inFile.is_open()) {
                qDebug() << "无法打开文件 data.txt";
            }

            // 读取所有行到 vector
            vector<string> lines;
            string line;
            while (getline(inFile, line)) {
                lines.push_back(line);
            }
            inFile.close();

            // 检查索引是否有效
            if (i < 0 || i >= static_cast<int>(lines.size()) - 1) { // 第0行是类型总数，不能删除
                qDebug() << "无效的行索引";
            }

            // 删除指定行（注意：第0行是类型总数，数据行从第1行开始）
            lines.erase(lines.begin() + i + 1);

            // 重新写入文件
            std::ofstream outFile("data.txt", std::ios::trunc);
            if (!outFile.is_open()) {
                qDebug() << "无法写入文件 data.txt";
            }

            for (const auto& l : lines) {
                outFile << l << "\n";
            }
            outFile.close();

            // 添加新物品
            object object1;//创建物品类对象
            if(object1.Add(k,s11,s12,s13,ID,s14,s15,s16,s17,s18,s19,s20))
            {
                object1.Writefile("data.txt");   //写入文件
                QMessageBox::information(this, "提示", "修改物品成功", QMessageBox::Ok);
            }
        }
    }


    void addobject()
    {
        string s;  //读取第一行类型数专用

        //保存文件存储的7个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;

        //读取类型文件
        ifstream inputFile("kinds.txt");
        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//读取第一行物品数

        int num = stringToInt(s);//保存第一行物品数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 8);  // 创建num行8列的表格

        table->setHorizontalHeaderLabels({"类型名称","操作"});
        table->verticalHeader()->setVisible(false);

        //表格后6行不展示，仅存储数据用
        for (int col = 2; col < 8; ++col)
        {
            table->setColumnHidden(col, true);
        }

        table->setColumnWidth(0, 200);  // 第一列宽度设为200像素
        table->setColumnWidth(1, 200);  // 第二列宽度设为200像素

        int i=0;
        while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\n'))

        {
            // 设置表格内容
            QString q1 = std2qstr(s1);
            QString q3 = std2qstr(s2);
            QString q4 = std2qstr(s3);
            QString q5 = std2qstr(s4);
            QString q6 = std2qstr(s5);
            QString q7 = std2qstr(s6);
            QString q8 = std2qstr(s7);
            table->setItem(i, 0, new QTableWidgetItem(q1));
            table->setItem(i, 2, new QTableWidgetItem(q3));
            table->setItem(i, 3, new QTableWidgetItem(q4));
            table->setItem(i, 4, new QTableWidgetItem(q5));
            table->setItem(i, 5, new QTableWidgetItem(q6));
            table->setItem(i, 6, new QTableWidgetItem(q7));
            table->setItem(i, 7, new QTableWidgetItem(q8));

            //设置添加物品类型按钮
            QPushButton *button1 = new QPushButton("添加该类型的物品");
            button1->setFixedWidth(200);
            table->setCellWidget(i, 1, button1);

            connect(button1, &QPushButton::clicked, [this,table, i]()
                    {
                        QString q1 = table->item(i, 0)->text();//获取物品类型(第一列)
                        QString q3 = table->item(i, 2)->text();//获取属性数(第三列)
                        string q=qstr2std(q3);
                        int num1 = stringToInt(q);

                        //读取物品文件
                        ifstream inputFile("data.txt");
                        if (!inputFile.is_open())

                        {

                            qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

                        }
                        string s;
                        getline(inputFile, s,'\n');//读取第一行物品数
                        inputFile.close();
                        int num = stringToInt(s);//保存第一行物品数

                        //显示添加物品对话框
                        QString q4 = table->item(i, 3)->text();
                        QString q5 = table->item(i, 4)->text();
                        QString q6 = table->item(i, 5)->text();
                        QString q7 = table->item(i, 6)->text();
                        QString q8 = table->item(i, 7)->text();
                        ShowAddObjectDialog(num,q1,num1,q4,q5,q6,q7,q8);

                        //窗口循环显示
                        this->addobject();

                        //关闭整个窗口
                        QWidget* topLevelWindow = table->window();
                        if (topLevelWindow && topLevelWindow != this) {
                            topLevelWindow->close();
                            topLevelWindow->deleteLater();
                        }

                    });
            i++;

        }
        // 布局设置
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入表格（居中）
        layout2->addWidget(table);
        layout2->setAlignment(Qt::AlignCenter);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("物品类型表格");
        window->resize(800, 400);
        window->show();

        inputFile.close(); //关闭文件

    }
    void showMyObject()
    {
        string s;  //去除保存行数的一行

        //保存文件存储的13个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;
        string s8;
        string s9;
        string s10;
        string s11;
        string s12;
        string s13;

        //读取物品文件
        ifstream inputFile("data.txt");

        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//读取保存行数的一行

        int num = stringToInt(s);//保存表格行数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 15);  // 新建表格

        //表格后8行不展示，仅存储数据用
        for (int col = 7; col < 15; ++col)
        {
            table->setColumnHidden(col, true);
        }

        table->setHorizontalHeaderLabels({"物品类型","物品名称","物品所在地址","物品状态","查看详细信息", "操作1", "操作2"});

        table->verticalHeader()->setVisible(false);

        int i=0;
        int tableHigh=0;//记录表长，截短表格时用
        while (  getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\t')&&getline(inputFile, s8,'\t')&&getline(inputFile, s9,'\t')
               &&getline(inputFile, s10,'\t')&&getline(inputFile, s11,'\t')&&getline(inputFile, s12,'\t')
               &&getline(inputFile, s13,'\n'))
        {

            qDebug()<<s5<<" "<<ID<<"\n";
            if(s5!=ID)
            {
                i++;
                continue;//不是我的物品，跳过
            }

            QString q1 = std2qstr(s1);//物品类型
            QString q2 = std2qstr(s2);//物品名称
            QString q3 = std2qstr(s4);//物品所在地址
            QString q8 = std2qstr(s3);//物品说明
            QString q9 = std2qstr(s6);//联系人手机
            QString q10 = std2qstr(s7);//联系人邮箱
            QString q11 = std2qstr(s8);//属性1
            QString q12 = std2qstr(s9);//属性2
            QString q13 = std2qstr(s10);//属性3
            QString q14 = std2qstr(s11);//属性4
            QString q15 = std2qstr(s12);//属性5
            table->setItem(tableHigh, 0, new QTableWidgetItem(q1));
            table->setItem(tableHigh, 1, new QTableWidgetItem(q2));
            table->setItem(tableHigh, 2, new QTableWidgetItem(q3));
            table->setItem(tableHigh, 7, new QTableWidgetItem(q8));
            table->setItem(tableHigh, 8, new QTableWidgetItem(q9));
            table->setItem(tableHigh, 9, new QTableWidgetItem(q10));
            table->setItem(tableHigh, 10, new QTableWidgetItem(q11));
            table->setItem(tableHigh, 11, new QTableWidgetItem(q12));
            table->setItem(tableHigh, 12, new QTableWidgetItem(q13));
            table->setItem(tableHigh, 13, new QTableWidgetItem(q14));
            table->setItem(tableHigh, 14, new QTableWidgetItem(q15));

            //添加查看详细信息按钮
            QPushButton *button0 = new QPushButton("查看详细信息");
            table->setCellWidget(tableHigh, 4, button0);

            connect(button0, &QPushButton::clicked, [this,table, tableHigh]() {

                string s;  //读取第一行类型数专用

                //保存文件存储的7个部分的信息
                string s1; //物品类型名（文件读出）
                string s2;
                string s3;
                string s4;
                string s5;
                string s6;
                string s7;

                QString q41 = table->item(tableHigh, 0)->text();//物品类型名（表中读出）

                //读取类型文件
                ifstream inputFile("kinds.txt");
                if (!inputFile.is_open())

                {

                    qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

                }

                getline(inputFile, s,'\n');//读取第一行类型数

                while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                       &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

                {
                    if(q41==std2qstr(s1))
                        break;              //找到要找的类型，退出循环

                }
                QString q61=std2qstr(s3);
                QString q62=std2qstr(s4);
                QString q63=std2qstr(s5);
                QString q64=std2qstr(s6);
                QString q65=std2qstr(s7);


                QWidget *window2 = new QWidget; // 新建窗口
                window2->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存
                QTableWidget *table2 = new QTableWidget(8, 1);
                table2->setHorizontalHeaderLabels({"物品详细信息"});
                table2->setVerticalHeaderLabels(QStringList{"联系人手机", "联系人邮箱", q61, q62,q63,q64,q65,"物品说明"});
                QString q51 = table->item(tableHigh, 8)->text();//联系人手机
                QString q52 = table->item(tableHigh, 9)->text();//联系人邮箱
                QString q53 = table->item(tableHigh, 10)->text();//属性1
                QString q54 = table->item(tableHigh, 11)->text();//属性2
                QString q55 = table->item(tableHigh, 12)->text();//属性3
                QString q56 = table->item(tableHigh, 13)->text();//属性4
                QString q57 = table->item(tableHigh, 14)->text();//属性5
                QString q58 = table->item(tableHigh, 7)->text();//物品说明
                table2->setItem(0, 0, new QTableWidgetItem(q51));
                table2->setItem(1, 0, new QTableWidgetItem(q52));

                //判断是否有属性1
                if (!q61.isEmpty()) {
                    table2->setItem(2, 0, new QTableWidgetItem(q53));
                } else {
                    table2->setRowHidden(2, true); // 隐藏第三行
                }

                //判断是否有属性2
                if (!q62.isEmpty()) {
                    table2->setItem(3, 0, new QTableWidgetItem(q54));
                } else {
                    table2->setRowHidden(3, true); // 隐藏第四行
                }

                //判断是否有属性3
                if (!q63.isEmpty()) {
                    table2->setItem(4, 0, new QTableWidgetItem(q55));
                } else {
                    table2->setRowHidden(4, true); // 隐藏第五行
                }

                //判断是否有属性4
                if (!q64.isEmpty()) {
                    table2->setItem(5, 0, new QTableWidgetItem(q56));
                } else {
                    table2->setRowHidden(5, true); // 隐藏第六行
                }

                //判断是否有属性5
                if (!q65.isEmpty()) {
                    table2->setItem(6, 0, new QTableWidgetItem(q57));
                } else {
                    table2->setRowHidden(6, true); // 隐藏第七行
                }

                //物品说明从左侧底部开始显示
                QTableWidgetItem *item = new QTableWidgetItem(q58);
                item->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                item->setFlags(item->flags() | Qt::ItemIsEditable);
                table2->setItem(7, 0, item);

                table2->setColumnWidth(0, 400);  // 第一列宽度设为400像素
                table2->setRowHeight(7, 200); // 第八行高度设为400像素
                QHBoxLayout *layout3 = new QHBoxLayout;  //新建布局

                //布局加入表格
                layout3->addWidget(table2);
                //界面展示布局，并设置名称、大小
                window2->setLayout(layout3);
                window2->setWindowTitle("详细信息");
                window2->resize(500, 600);
                window2->show();
            });

            //物品状态为审核通过物品
            if(s13=="1")
            // 设置表格内容
            {
                QString q4 = "审核通过物品";//物品状态
                table->setItem(tableHigh, 3, new QTableWidgetItem(q4));

                //添加修改物品、删除物品按钮
                QPushButton *button1 = new QPushButton("修改物品");
                QPushButton *button2 = new QPushButton("删除物品");
                table->setCellWidget(tableHigh, 5, button1);
                table->setCellWidget(tableHigh, 6, button2);


                //点击修改物品按钮，弹出修改物品对话框
                connect(button1, &QPushButton::clicked, [this,table ,tableHigh,i]() {
                    QString q1 = table->item(tableHigh, 0)->text();//物品类型
                    QString q2 = table->item(tableHigh, 1)->text();//物品名称
                    QString q3 = table->item(tableHigh, 2)->text();//物品所在地址
                    QString q8 = table->item(tableHigh, 7)->text();//物品说明
                    QString q9 = table->item(tableHigh, 8)->text();//联系人手机
                    QString q10 = table->item(tableHigh, 9)->text();//联系人邮箱
                    QString q11 = table->item(tableHigh, 10)->text();//属性1
                    QString q12 = table->item(tableHigh, 11)->text();//属性2
                    QString q13 = table->item(tableHigh, 12)->text();//属性3
                    QString q14 = table->item(tableHigh, 13)->text();//属性4
                    QString q15 = table->item(tableHigh, 14)->text();//属性5

                    //弹出修改物品对话框
                    ShowReviseObjectDialog(q1,q2,q3,q8,q9,q10,q11,q12,q13,q14,q15,i);

                    //刷新数据
                    this->showMyObject();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });

                //点击删除物品按钮，将文件状态改为已删除
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    QFile file("data.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开数据文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i+1; // 第i+2行（索引为i+1）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为已删除）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '4');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "删除物品成功");
                    //刷新数据
                    this->showMyObject();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });
                tableHigh++;
            }
            //物品状态为审核中物品，显示物品等待管理员审核
            if(s13=="2")
            {
                QString q4 ="待审核物品";//物品状态
                table->setItem(tableHigh, 3, new QTableWidgetItem(q4));
                QString q5="等待管理员审核";
                table->setItem(tableHigh, 5, new QTableWidgetItem(q5));
                tableHigh++;
            }

            //物品状态为待修改物品
            if(s13=="3")
            // 设置表格内容
            {
                QString q4 = "待修改物品";//物品状态
                table->setItem(tableHigh, 3, new QTableWidgetItem(q4));
                //添加修改物品、删除物品按钮
                QPushButton *button1 = new QPushButton("修改物品");
                QPushButton *button2 = new QPushButton("删除物品");
                table->setCellWidget(tableHigh, 5, button1);
                table->setCellWidget(tableHigh, 6, button2);


                //点击修改物品按钮，弹出修改物品对话框
                connect(button1, &QPushButton::clicked, [this,table ,tableHigh,i]() {
                    QString q1 = table->item(tableHigh, 0)->text();//物品类型
                    QString q2 = table->item(tableHigh, 1)->text();//物品名称
                    QString q3 = table->item(tableHigh, 2)->text();//物品所在地址
                    QString q8 = table->item(tableHigh, 7)->text();//物品说明
                    QString q9 = table->item(tableHigh, 8)->text();//联系人手机
                    QString q10 = table->item(tableHigh, 9)->text();//联系人邮箱
                    QString q11 = table->item(tableHigh, 10)->text();//属性1
                    QString q12 = table->item(tableHigh, 11)->text();//属性2
                    QString q13 = table->item(tableHigh, 12)->text();//属性3
                    QString q14 = table->item(tableHigh, 13)->text();//属性4
                    QString q15 = table->item(tableHigh, 14)->text();//属性5

                    //弹出修改物品对话框
                    ShowReviseObjectDialog(q1,q2,q3,q8,q9,q10,q11,q12,q13,q14,q15,i);

                    //刷新数据
                    this->showMyObject();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });

                //点击删除物品按钮，将文件状态改为已删除
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    QFile file("data.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开数据文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i+1; // 第i+2行（索引为i+1）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '4');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "删除物品成功");
                    //刷新数据
                    this->showMyObject();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });
                tableHigh++;
            }

            //物品状态为已删除物品
            if(s13=="4")
            {
                QString q4 ="已删除物品";//物品状态
                table->setItem(tableHigh, 3, new QTableWidgetItem(q4));
                //添加重新编辑改物品、永久删除物品按钮
                QPushButton *button1 = new QPushButton("永久删除物品");
                QPushButton *button2 = new QPushButton("重新编辑物品");
                table->setCellWidget(tableHigh, 5, button1);
                table->setCellWidget(tableHigh, 6, button2);

                //点击永久删除物品按钮，将物品从文件中彻底删除
                connect(button1, &QPushButton::clicked, [this,table, i]()
                        {
                            // 删除文件中的第 i+1 行（行号从0开始计数）

                            // 打开文件读取
                            ifstream inFile("data.txt");
                            if (!inFile.is_open()) {
                                qDebug() << "无法打开文件 data.txt";
                            }

                            // 读取所有行到 vector
                            vector<string> lines;
                            string line;
                            while (getline(inFile, line)) {
                                lines.push_back(line);
                            }
                            inFile.close();

                            // 检查索引是否有效
                            if (i < 0 || i >= static_cast<int>(lines.size()) - 1) { // 第0行是类型总数，不能删除
                                qDebug() << "无效的行索引";
                            }

                            // 删除指定行（注意：第0行是类型总数，数据行从第1行开始）
                            lines.erase(lines.begin() + i + 1);

                            // 更新第一行的类型总数
                            if (!lines.empty()) {
                                int newCount = stoi(lines[0]) - 1;
                                lines[0] = to_string(newCount);
                            }

                            // 重新写入文件
                            std::ofstream outFile("data.txt", std::ios::trunc);
                            if (!outFile.is_open()) {
                                qDebug() << "无法写入文件 data.txt";
                            }

                            for (const auto& l : lines) {
                                outFile << l << "\n";
                            }
                            outFile.close();
                            QMessageBox::information(this, "提示", "操作成功！", QMessageBox::Ok);

                            //刷新窗口
                            this->showMyObject();

                            //关闭整个窗口
                            QWidget* topLevelWindow = table->window();
                            if (topLevelWindow && topLevelWindow != this)
                            {
                                topLevelWindow->close();
                                topLevelWindow->deleteLater();
                            }
                        });
                //点击重新编辑物品按钮，将物品状态改为待修改
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    QFile file("data.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开数据文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i+1; // 第i+2行（索引为i+1）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '3');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "恢复物品成功，请继续修改物品！");

                    //刷新数据
                    this->showMyObject();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });

                tableHigh++;
            }
            i++;

        }

        // 布局设置
        table->setRowCount(tableHigh);
        QLabel *label1 = new QLabel("你共添加了" + QString::number(tableHigh) + "个物品");
        label1->setFixedWidth(120);
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入标签、表格
        layout2->addWidget(label1);
        layout2->addWidget(table);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("我的物品表格");
        window->resize(900, 600);
        window->show();
    }
};


//管理员窗口类，继承自QWidget
class  AdministratorWindow : public QWidget {
    Q_OBJECT
public:
    AdministratorWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("物品复活软件");  // 设置窗口标题
        setFixedSize(800, 400);  // 固定窗口大小
        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);
        setLayout(layout);  // 关键：设置布局

        // 设置新的物品类型按钮
        QPushButton *Button1 = new QPushButton("设置新的物品类型");
        Button1->setFixedWidth(200);
        Button1->setFixedHeight(50);
        layout->addWidget(Button1);  // 添加到布局

        // 修改已有的物品类型按钮
        QPushButton *Button2 = new QPushButton("修改已有的物品类型");
        Button2->setFixedWidth(200);
        Button2->setFixedHeight(50);
        layout->addWidget(Button2);  // 添加到布局


        // 审核用户添加的物品
        QPushButton *Button3 = new QPushButton("审核用户添加的物品");
        Button3->setFixedHeight(50);
        Button3->setFixedWidth(200);
        layout->addWidget(Button3);  // 添加到布局

        // 审核新注册的用户
        QPushButton *Button4 = new QPushButton("审核新注册的用户");
        Button4->setFixedHeight(50);
        Button4->setFixedWidth(200);
        layout->addWidget(Button4);  // 添加到布局

        // 删除物品
        QPushButton *Button5 = new QPushButton("删除物品");
        Button5->setFixedWidth(200);
        Button5->setFixedHeight(50);
        layout->addWidget(Button5);  // 添加到布局

        // 关闭应用
        QPushButton *Button6 = new QPushButton("关闭应用");
        Button6->setFixedWidth(200);
        Button6->setFixedHeight(50);
        layout->addWidget(Button6);  // 添加到布局
        setLayout(layout);
        layout->setAlignment(Qt::AlignCenter);


        // 连接信号槽
        connect(Button1, &QPushButton::clicked, this, &AdministratorWindow::addKind);
        connect(Button2, &QPushButton::clicked, this, &AdministratorWindow::reviseKind);
        connect(Button3, &QPushButton::clicked, this, &AdministratorWindow::objectaudit);
        connect(Button4, &QPushButton::clicked, this, &AdministratorWindow::useraudit);
        connect(Button5, &QPushButton::clicked, this, &AdministratorWindow::DeleteObject);
        connect(Button6, &QPushButton::clicked, this, &AdministratorWindow::close);

    }

private slots:

    void DeleteObject() {
        string s;  //去除保存行数的一行
        //保存文件存储的13个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;
        string s8;
        string s9;
        string s10;
        string s11;
        string s12;
        string s13;

        //读取物品文件
        ifstream inputFile("data.txt");

        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//去除保存行数的一行

        int num = stringToInt(s);//保存表格行数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 14);  // 新建表格
        QLabel *label1 = new QLabel("");
        QComboBox *comboBox = new QComboBox(); // 新建选框

        //保存文件存储的7个部分的信息
        string ss;
        string ss1;
        string ss2;
        string ss3;
        string ss4;
        string ss5;
        string ss6;
        string ss7;

        //读取类型文件
        ifstream inputFile2("kinds.txt");
        if (!inputFile2.is_open())
        {

            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

        }

        getline(inputFile2, ss,'\n');//读取第一行物品数
        int j=0;
        while (  getline(inputFile2, ss1,'\t')&&getline(inputFile2, ss2,'\t')&&getline(inputFile2, ss3,'\t')
               &&getline(inputFile2, ss4,'\t')&&getline(inputFile2, ss5,'\t')&&getline(inputFile2, ss6,'\t')
               &&getline(inputFile2, ss7,'\n'))

        {
            // 设置选框内容
            QString q21 = std2qstr(ss1);
            comboBox->addItem(QString(q21).arg(j+1));
            j++;
        }

        connect(comboBox, QOverload<int>::of(&QComboBox::activated),
                [this, comboBox, table,label1](int index) {
                    // 初始化可见行计数器
                    int visibleRowCount = 0;

                    // 处理无效索引（-1表示无选择）
                    if (index == -1) {
                        // 显示所有行（重置筛选）
                        for (int row = 0; row < table->rowCount(); ++row) {
                            table->setRowHidden(row, false);
                        }
                        visibleRowCount = table->rowCount();
                        int a = visibleRowCount;

                        // 设置标签文本：显示可见行数
                        label1->setText(QString::number(a));
                        return;
                    }

                    // 获取当前选中项的文本
                    QString selectedText = comboBox->currentText();

                    bool shouldShow;
                    // 遍历表格所有行
                    for (int row = 0; row < table->rowCount(); ++row) {
                        // 获取第一列（列索引0）的单元格
                        QTableWidgetItem* item = table->item(row, 0);

                        // 检查单元格是否存在且文本匹配
                        shouldShow = item && (item->text() == selectedText);
                        table->setRowHidden(row, !shouldShow);

                        // 如果该行可见，增加计数器
                        if (shouldShow) {
                            visibleRowCount++;
                        }
                    }

                    // 将可见行数保存在变量a中
                    int a = visibleRowCount;

                    // 设置标签文本：显示可见行数
                    label1->setText("该类型共有"+QString::number(a)+"个物品");

                    //弹出搜索框
                    this->showMinimized();
                    SearchObjectDialog dialog(this);

                    if (dialog.exec() == QDialog::Accepted) {
                        // 如果用户点击确定，获取输入内容
                        QString input1 = dialog.getInput1();
                        int visibleRowCount=0;
                        for (int row = 0; row < table->rowCount(); ++row) {
                            // 获取第一列（列索引0）的单元格
                            QTableWidgetItem* item1 = table->item(row, 1);
                            QTableWidgetItem* item3 = table->item(row, 3);
                            QTableWidgetItem* item5 = table->item(row, 6);
                            QTableWidgetItem* item =  table->item(row, 0);

                            // 检查单元格是否包含搜索的文本且是所选类型
                            bool shouldShow2 = ((item1->text().contains(input1, Qt::CaseSensitive))
                                                ||(item3->text().contains(input1, Qt::CaseSensitive))
                                                ||(item5->text().contains(input1, Qt::CaseSensitive)))&&(item->text() == selectedText);

                            // 隐藏不包含搜索的文本的行
                            table->setRowHidden(row, !shouldShow2);

                            // 如果该行可见，增加计数器
                            if (shouldShow2) {
                                visibleRowCount++;
                            }
                        }
                        int a = visibleRowCount;
                        label1->setText("共搜索到"+QString::number(a)+"个物品");
                    }

                });


        //表格后8行不展示，仅存储数据用
        for (int col = 6; col < 14; ++col)
        {
            table->setColumnHidden(col, true);
        }

        table->setHorizontalHeaderLabels({"物品类型","物品名称","物品所在地址","添加用户","查看详细信息","删除物品"});
        table->verticalHeader()->setVisible(false);

        int i=0;
        int k=0;
        while (  getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\t')&&getline(inputFile, s8,'\t')&&getline(inputFile, s9,'\t')
               &&getline(inputFile, s10,'\t')&&getline(inputFile, s11,'\t')&&getline(inputFile, s12,'\t')
               &&getline(inputFile, s13,'\n'))
        {
            //不是审核通过物品，不展示
            if(s13!="1")
            {
                k++;
                continue;
            }

            QString q1 = std2qstr(s1);//物品类型
            QString q2 = std2qstr(s2);//物品名称
            QString q3 = std2qstr(s4);//物品所在地址
            QString q4 = std2qstr(s5);;//添加用户
            QString q8 = std2qstr(s3);//物品说明
            QString q9 = std2qstr(s6);//联系人手机
            QString q10 = std2qstr(s7);//联系人邮箱
            QString q11 = std2qstr(s8);//属性1
            QString q12 = std2qstr(s9);//属性2
            QString q13 = std2qstr(s10);//属性3
            QString q14 = std2qstr(s11);//属性4
            QString q15 = std2qstr(s12);//属性5

            //添加到表格中
            table->setItem(i, 0, new QTableWidgetItem(q1));
            table->setItem(i, 1, new QTableWidgetItem(q2));
            table->setItem(i, 2, new QTableWidgetItem(q3));
            table->setItem(i, 3, new QTableWidgetItem(q4));
            table->setItem(i, 6, new QTableWidgetItem(q8));
            table->setItem(i, 7, new QTableWidgetItem(q9));
            table->setItem(i, 8, new QTableWidgetItem(q10));
            table->setItem(i, 9, new QTableWidgetItem(q11));
            table->setItem(i, 10, new QTableWidgetItem(q12));
            table->setItem(i, 11, new QTableWidgetItem(q13));
            table->setItem(i, 12, new QTableWidgetItem(q14));
            table->setItem(i, 13, new QTableWidgetItem(q15));

            //添加查看详细信息按钮与删除物品按钮
            QPushButton *button0 = new QPushButton("查看详细信息");
            table->setCellWidget(i, 4, button0);
            QPushButton *button1 = new QPushButton("删除物品");
            table->setCellWidget(i, 5, button1);

            //点击删除物品按钮，改变物品状态
            connect(button1, &QPushButton::clicked, [this,table, k]() {
                QFile file("data.txt");
                if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                    QMessageBox::critical(table, "错误", "无法打开数据文件！");
                    return;
                }

                // 读取所有行到内存
                QStringList lines;
                QTextStream in(&file);
                while (!in.atEnd()) {
                    lines << in.readLine();
                }

                // 检查目标行是否存在
                int targetLine = k+1; // 第k+2行（索引为k+1）
                if (targetLine >= lines.size()) {
                    QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                    file.close();
                    return;
                }

                // 修改目标行的最后一个字符（改为已删除）
                QString target = lines[targetLine];
                if (!target.isEmpty()) {
                    target.replace(target.length() - 1, 1, '4');
                    lines[targetLine] = target;
                }

                // 写回文件
                file.resize(0); // 清空原文件内容
                in.seek(0);
                for (const QString &line : lines) {
                    in << line << "\n";
                }

                file.close();

                // 弹出成功消息
                QMessageBox::information(table, "操作成功", "删除物品成功");

                //刷新数据
                this->DeleteObject();

                //关闭整个窗口
                QWidget* topLevelWindow = table->window();
                if (topLevelWindow && topLevelWindow != this) {
                    topLevelWindow->close();
                    topLevelWindow->deleteLater();
                }


            });

            //点击查看详细信息按钮，弹出详细信息表格
            connect(button0, &QPushButton::clicked, [this,table, i]() {
                string s;  //读取第一行类型数专用

                //保存文件存储的7个部分的信息
                string s1; //物品类型名（文件读出）
                string s2;
                string s3;
                string s4;
                string s5;
                string s6;
                string s7;

                QString q41 = table->item(i, 0)->text();//物品类型名（表中读出）

                //读取类型文件
                ifstream inputFile("kinds.txt");
                if (!inputFile.is_open())

                {

                    qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

                }

                getline(inputFile, s,'\n');//读取第一行类型数

                while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                       &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

                {
                    if(q41==std2qstr(s1))
                        break;

                }
                QString q61=std2qstr(s3);
                QString q62=std2qstr(s4);
                QString q63=std2qstr(s5);
                QString q64=std2qstr(s6);
                QString q65=std2qstr(s7);


                QWidget *window2 = new QWidget;                 // 新建窗口
                window2->setAttribute(Qt::WA_DeleteOnClose);    // 关闭时自动释放内存
                QTableWidget *table2 = new QTableWidget(8, 1);  // 新建表格
                table2->setHorizontalHeaderLabels({"物品详细信息"});
                table2->setVerticalHeaderLabels(QStringList{"联系人手机", "联系人邮箱", q61, q62,q63,q64,q65,"物品说明"});

                //从表格中读取内容
                QString q51 = table->item(i, 7)->text();//联系人手机
                QString q52 = table->item(i, 8)->text();//联系人邮箱
                QString q53 = table->item(i, 9)->text();//属性1
                QString q54 = table->item(i, 10)->text();//属性2
                QString q55 = table->item(i, 11)->text();//属性3
                QString q56 = table->item(i, 12)->text();//属性4
                QString q57 = table->item(i, 13)->text();//属性5
                QString q58 = table->item(i, 6)->text();//物品说明
                table2->setItem(0, 0, new QTableWidgetItem(q51));
                table2->setItem(1, 0, new QTableWidgetItem(q52));

                //判断是否存在属性1
                if (!q61.isEmpty()) {
                    table2->setItem(2, 0, new QTableWidgetItem(q53));
                } else {
                    table2->setRowHidden(2, true); // 隐藏第三行
                }

                //判断是否存在属性2
                if (!q62.isEmpty()) {
                    table2->setItem(3, 0, new QTableWidgetItem(q54));
                } else {
                    table2->setRowHidden(3, true); // 隐藏第四行
                }

                //判断是否存在属性3
                if (!q63.isEmpty()) {
                    table2->setItem(4, 0, new QTableWidgetItem(q55));
                } else {
                    table2->setRowHidden(4, true); // 隐藏第五行
                }

                //判断是否存在属性4
                if (!q64.isEmpty()) {
                    table2->setItem(5, 0, new QTableWidgetItem(q56));
                } else {
                    table2->setRowHidden(5, true); // 隐藏第六行
                }

                //判断是否存在属性5
                if (!q65.isEmpty()) {
                    table2->setItem(6, 0, new QTableWidgetItem(q57));
                } else {
                    table2->setRowHidden(6, true); // 隐藏第七行
                }

                //物品说明从表格左侧最上方开始
                QTableWidgetItem *item = new QTableWidgetItem(q58);
                item->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                item->setFlags(item->flags() | Qt::ItemIsEditable);
                table2->setItem(7, 0, item);

                table2->setColumnWidth(0, 400);  // 第一列宽度设为400像素
                table2->setRowHeight(7, 200); // 第八行高度设为400像素

                QHBoxLayout *layout3 = new QHBoxLayout;

                //布局加入表格
                layout3->addWidget(table2);

                //界面展示布局，并设置名称、大小
                window2->setLayout(layout3);
                window2->setWindowTitle("详细信息");
                window2->resize(500, 600);
                window2->show();

            });
            i++;
            k++;
        }
        table->setRowCount(i);
        label1->setText("目前一共有" + QString::number(i) + "个物品");
        label1->setFixedWidth(120);
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入标签、选框、表格
        layout2->addWidget(label1);
        layout2->addWidget(comboBox);
        layout2->addWidget(table);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("搜索物品表格");
        window->resize(900, 600);
        window->show();
    }


    void useraudit() {

        string s;  //去除保存行数的一行

        //保存文件存储的6个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;

        //读取账户文件
        ifstream inputFile("account.txt");

        if (!inputFile.is_open())
        {

            qDebug() << "无法打开文件 account.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//去除保存行数的一行

        int num = stringToInt(s);//保存表格行数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 7);  // 新建表格

        table->setHorizontalHeaderLabels({"用户名","用户住址","用户电话","用户邮箱","用户状态", "操作1", "操作2"});

        table->verticalHeader()->setVisible(false);

        //去除管理员的两行
        getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
            &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\n');
        getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
            &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\n');

        int i=0;

        while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\n'))

        {
            // 设置表格内容
            QString q1 = std2qstr(s1);
            QString q2 = std2qstr(s3);
            QString q3 = std2qstr(s4);
            QString q4 = std2qstr(s5);

            //用户为正式用户
            if(s6=="1")
            {
                QString q5 = "正式用户";

                // 表格填充
                table->setItem(i, 0, new QTableWidgetItem(q1));
                table->setItem(i, 1, new QTableWidgetItem(q2));
                table->setItem(i, 2, new QTableWidgetItem(q3));
                table->setItem(i, 3, new QTableWidgetItem(q4));
                table->setItem(i, 4, new QTableWidgetItem(q5));

                //添加封禁用户、删除用户按钮
                QPushButton *button1 = new QPushButton("封禁用户");
                QPushButton *button2 = new QPushButton("删除用户");
                table->setCellWidget(i, 5, button1);
                table->setCellWidget(i, 6, button2);

                //点击封禁用户按钮
                connect(button1, &QPushButton::clicked, [this,table, i]() {

                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（封禁用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '4');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "封禁用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });

                //点击删除用户按钮
                connect(button2, &QPushButton::clicked, [this,table, i]() {

                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（已删除用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '5');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "删除用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });
            }

            //用户为待审核用户
            if(s6=="2")
            {
                QString q5 = "待审核用户";
                // 表格填充
                table->setItem(i, 0, new QTableWidgetItem(q1));
                table->setItem(i, 1, new QTableWidgetItem(q2));
                table->setItem(i, 2, new QTableWidgetItem(q3));
                table->setItem(i, 3, new QTableWidgetItem(q4));
                table->setItem(i, 4, new QTableWidgetItem(q5));

                //添加通过用户、拒绝用户按钮
                QPushButton *button1 = new QPushButton("通过用户");
                QPushButton *button2= new QPushButton("拒绝用户");
                table->setCellWidget(i, 5, button1);
                table->setCellWidget(i, 6, button2);

                //点击通过用户按钮
                connect(button1, &QPushButton::clicked, [this,table, i]() {
                    // 文打开件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为正式用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '1');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "通过用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });
                //点击拒绝用户按钮
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为已拒绝用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '3');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "拒绝用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });

            }

            //用户为已拒绝用户
            if(s6=="3")
            {
                QString q5 = "已拒绝用户";
                // 表格填充
                table->setItem(i, 0, new QTableWidgetItem(q1));
                table->setItem(i, 1, new QTableWidgetItem(q2));
                table->setItem(i, 2, new QTableWidgetItem(q3));
                table->setItem(i, 3, new QTableWidgetItem(q4));
                table->setItem(i, 4, new QTableWidgetItem(q5));

                //添加取消拒绝用户、删除用户按钮
                QPushButton *button1 = new QPushButton("取消拒绝用户");
                QPushButton *button2 = new QPushButton("删除用户");
                table->setCellWidget(i, 5, button1);
                table->setCellWidget(i, 6, button2);

                //点击取消拒绝用户按钮
                connect(button1, &QPushButton::clicked, [this,table, i]() {
                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为待审核用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '2');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "取消拒绝用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });

                //点击删除用户按钮
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（已删除用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '5');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "删除用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });
            }

            //用户为封禁用户
            if(s6=="4")
            {
                QString q5 = "封禁用户";
                // 表格填充
                table->setItem(i, 0, new QTableWidgetItem(q1));
                table->setItem(i, 1, new QTableWidgetItem(q2));
                table->setItem(i, 2, new QTableWidgetItem(q3));
                table->setItem(i, 3, new QTableWidgetItem(q4));
                table->setItem(i, 4, new QTableWidgetItem(q5));

                //添加解封用户、删除用户按钮
                QPushButton *button1 = new QPushButton("解封用户");
                QPushButton *button2 = new QPushButton("删除用户");
                table->setCellWidget(i, 5, button1);
                table->setCellWidget(i, 6, button2);

                //点击解封用户按钮
                connect(button1, &QPushButton::clicked, [this,table, i]() {
                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为正式用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '1');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "解封用户成功");

                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });

                //点击删除用户按钮
                connect(button2, &QPushButton::clicked, [this,table, i]() {
                    // 打开文件
                    QFile file("Account.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i + 3; // 第i+4行（索引为i+3）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为已删除用户）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '5');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();
                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "删除用户成功");
                    //刷新数据
                    this->useraudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                });
            }

            //用户为已删除用户
            if(s6=="5")
            {
                QString q5 = "已删除用户";
                // 表格填充
                table->setItem(i, 0, new QTableWidgetItem(q1));
                table->setItem(i, 1, new QTableWidgetItem(q2));
                table->setItem(i, 2, new QTableWidgetItem(q3));
                table->setItem(i, 3, new QTableWidgetItem(q4));
                table->setItem(i, 4, new QTableWidgetItem(q5));
            }

            i++;
        }
        // 布局设置
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入表格
        layout2->addWidget(table);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("软件用户表格");
        window->resize(800, 400);
        window->show();

    }

    void addKind()
    {
        string s;  //读取第一行类型数专用

        //保存文件存储的7个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;

        //读取类型文件
        ifstream inputFile("kinds.txt");
        if (!inputFile.is_open())
        {
            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;
        }

        getline(inputFile, s,'\n');//读取第一行类型数

        int num = stringToInt(s);//保存第一行类型数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 6);  // 新建表格

        table->setHorizontalHeaderLabels({"类型名称","属性1","属性2","属性3","属性4", "属性5"});

        table->verticalHeader()->setVisible(false);

        int i=0;
        while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

        {
            // 设置表格内容
            QString q1 = std2qstr(s1);
            QString q2 = std2qstr(s3);
            QString q3 = std2qstr(s4);
            QString q4 = std2qstr(s5);
            QString q5 = std2qstr(s6);
            QString q6 = std2qstr(s7);
            table->setItem(i, 0, new QTableWidgetItem(q1));
            table->setItem(i, 1, new QTableWidgetItem(q2));
            table->setItem(i, 2, new QTableWidgetItem(q3));
            table->setItem(i, 3, new QTableWidgetItem(q4));
            table->setItem(i, 4, new QTableWidgetItem(q5));
            table->setItem(i, 5, new QTableWidgetItem(q6));
            i++;
        }
        // 布局设置
        QHBoxLayout *layout2 = new QHBoxLayout;
        layout2->addWidget(table);
        QPushButton *button1 = new QPushButton("添加物品类型");
        button1->setFixedWidth(170);
        button1->setFixedHeight(50);
        layout2->addWidget(button1);
        layout2->setAlignment(Qt::AlignCenter);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("物品类型表格");
        window->resize(800, 400);
        window->show();

        //点击添加物品类型按钮
        connect(button1, &QPushButton::clicked, this, [this, window]() {
            this->showAddkindDialog();  // 打开添加类型对话框
            window->close();            // 关闭当前类型表格窗口
        });
    }


    void showAddkindDialog()
    {
        AddKindDialog dialog(this);  // 创建对话框实例
        // 显示对话框并等待用户操作
        if (dialog.exec() == QDialog::Accepted) {
            // 如果用户点击确定，获取输入内容
            QString input1 = dialog.getInput1();
            QString input2 = dialog.getInput2();
            QString input3 = dialog.getInput3();
            QString input4 = dialog.getInput4();
            QString input5 = dialog.getInput5();
            QString input6 = dialog.getInput6();

            //物品类型名为空
            if(input1.isEmpty())
            {
                qDebug() << "物品类型名为空！";
                QMessageBox::information(this, "提示", "不能添加类型名为空的物品！", QMessageBox::Ok);
                return;
            }

            sortStrings(input2,input3,input4,input5,input6);//跳掉空的属性输入

            //转换为string类以便文件存储
            string s11 = qstr2std(input1);
            string s12 = qstr2std(input2);
            string s13 = qstr2std(input3);
            string s14 = qstr2std(input4);
            string s15 = qstr2std(input5);
            string s16 = qstr2std(input6);

            // 在控制台输出用户输入（调试用）
            qDebug() << "输入 物品类型:" << s11.c_str()
                     << "\n属性1" << s12.c_str()
                     << "\n属性2" << s13.c_str()
                     << "\n属性3" << s14.c_str()
                     << "\n属性4" << s15.c_str()
                     << "\n属性5" << s16.c_str();

            int z=0;         //判定类型名是否已经存在，0为不存在，1为存在
            Kinds k1;        //创建类型类对象

            string s;        //保存第一行记录的行数

            //保存文件存储的13个部分的信息
            string s1;
            string s2;
            string s3;
            string s4;
            string s5;
            string s6;
            string s7;

            //添加类型
            if(k1.Add(s11,s12,s13,s14,s15,s16))
            {
                //查询类型名是否已经存在
                ifstream inputFile("kinds.txt");
                if (!inputFile.is_open())
                {
                    qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;
                }
                getline(inputFile, s,'\n');//去除文件中第一行
                int L=stringToInt(s);//目前账号数

                while (getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                       &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
                       &&getline(inputFile, s7,'\n'))
                {
                    //类型名已经存在，添加失败
                    if((s1==k1.Return_a()))
                    {
                        QMessageBox::information(this, "提示", "该类型名已经存在，不能重复添加", QMessageBox::Ok);
                        z=1;
                        break;
                    }
                }
                //添加成功
                if(z==0)
                {
                    k1.Writefile("kinds.txt");          //写入文件
                    replaceFirstLine("kinds.txt",L+1);  //更改第一行的类型数（+1）
                    QMessageBox::information(this, "提示", "添加物品类型成功", QMessageBox::Ok);
                }

            }

        }
        //刷新数据
        addKind();

    }


    void showrevisekindDialog(QString q1,QString q2,QString q3, QString q4, QString q5, QString q6,int i)
    {
        reviseKindDialog dialog(this,q2,q3,q4,q5,q6);  // 创建对话框实例
        // 显示对话框并等待用户操作
        if (dialog.exec() == QDialog::Accepted) {
            // 如果用户点击确定，获取输入内容
            QString input2 = dialog.getInput2();
            QString input3 = dialog.getInput3();
            QString input4 = dialog.getInput4();
            QString input5 = dialog.getInput5();
            QString input6 = dialog.getInput6();
            sortStrings(input2,input3,input4,input5,input6);//跳掉空的属性输入

            //管理员未修改
            if((input2==q2)&&(input3==q3)&&(input4==q4)&&(input5==q5)&&(input6==q6))
            {
                qDebug() << "您做作出任何修改！";
                QMessageBox::information(this, "提示", "注意：您做作出任何修改！", QMessageBox::Ok);
            }
            else
            {
                //转换为string类以便文件存储
                string s11 = qstr2std(q1);
                string s12 = qstr2std(input2);
                string s13 = qstr2std(input3);
                string s14 = qstr2std(input4);
                string s15 = qstr2std(input5);
                string s16 = qstr2std(input6);

                // 在控制台输出用户输入（调试用）
                qDebug() << "输入 物品类型:"
                         << "\n属性1" << s12.c_str()
                         << "\n属性2" << s13.c_str()
                         << "\n属性3" << s14.c_str()
                         << "\n属性4" << s15.c_str()
                         << "\n属性5" << s16.c_str();

                //在类型中删除原类型所在行(第i+1行)
                // 打开文件读取
                ifstream inFile("kinds.txt");
                if (!inFile.is_open()) {
                    qDebug() << "无法打开文件 kinds.txt";
                }

                // 读取所有行到 vector
                vector<string> lines;
                string line;
                while (getline(inFile, line)) {
                    lines.push_back(line);
                }
                inFile.close();

                // 检查索引是否有效
                if (i < 0 || i >= static_cast<int>(lines.size()) - 1) { // 第0行是类型总数，不能删除
                    qDebug() << "无效的行索引";
                }

                // 删除指定行（注意：第0行是类型总数，数据行从第1行开始）
                lines.erase(lines.begin() + i + 1);


                // 重新写入文件
                std::ofstream outFile("kinds.txt", std::ios::trunc);
                if (!outFile.is_open()) {
                    qDebug() << "无法写入文件 kinds.txt";
                }

                for (const auto& l : lines) {
                    outFile << l << "\n";
                    qDebug() << l<< "\n";
                }
                outFile.close();


                //添加修改后的新类型
                Kinds k1;        //创建类型类对象
                if(k1.Add(s11,s12,s13,s14,s15,s16))
                {
                    ifstream inputFile("kinds.txt");
                    if (!inputFile.is_open())
                    {
                        qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;
                    }

                    //添加成功
                    k1.Writefile("kinds.txt");        //写入文件
                    QMessageBox::information(this, "提示", "修改物品类型成功", QMessageBox::Ok);

                }
            }
        }
    }



    void reviseKind()
    {
        string s;  //读取第一行类型数专用

        //保存文件存储的7个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;

        //读取类型文件
        ifstream inputFile("kinds.txt");
        if (!inputFile.is_open())
        {

            qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//读取第一行类型数

        int num = stringToInt(s);//保存第一行类型数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 8);  // 新建表格

        table->setHorizontalHeaderLabels({"类型名称","属性1","属性2","属性3","属性4", "属性5","操作1","操作2"});

        table->verticalHeader()->setVisible(false);

        int i=0;
        while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

        {
            // 设置表格内容
            QString q1 = std2qstr(s1);
            QString q2 = std2qstr(s3);
            QString q3 = std2qstr(s4);
            QString q4 = std2qstr(s5);
            QString q5 = std2qstr(s6);
            QString q6 = std2qstr(s7);
            table->setItem(i, 0, new QTableWidgetItem(q1));
            table->setItem(i, 1, new QTableWidgetItem(q2));
            table->setItem(i, 2, new QTableWidgetItem(q3));
            table->setItem(i, 3, new QTableWidgetItem(q4));
            table->setItem(i, 4, new QTableWidgetItem(q5));
            table->setItem(i, 5, new QTableWidgetItem(q6));

            //添加修改类型、删除类型按钮
            QPushButton *button1 = new QPushButton("修改类型");
            QPushButton *button2 = new QPushButton("删除类型");
            table->setCellWidget(i, 6, button1);
            table->setCellWidget(i, 7, button2);

            //点击修改类型按钮
            connect(button1, &QPushButton::clicked, [this,table, i]() {
                if(i==0)
                {
                    QMessageBox::information(this, "提示", "“其它”为默认类型，不可修改！", QMessageBox::Ok);
                }
                else
                {
                    //从表格中读取类型名及属性名作默认值
                    QString q1 = table->item(i, 0)->text();
                    QString q2 = table->item(i, 1)->text();
                    QString q3 = table->item(i, 2)->text();
                    QString q4 = table->item(i, 3)->text();
                    QString q5 = table->item(i, 4)->text();
                    QString q6 = table->item(i, 5)->text();

                    //显示修改类型输入框
                    showrevisekindDialog(q1,q2,q3,q4,q5,q6,i);

                    //刷新
                    this->reviseKind();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }
                }

                //使用该类型的物品全部变为待修改物品
                string ss;  //去除保存行数的一行

                //保存文件存储的13个部分的信息
                string ss1;
                string ss2;
                string ss3;
                string ss4;
                string ss5;
                string ss6;
                string ss7;
                string ss8;
                string ss9;
                string ss10;
                string ss11;
                string ss12;
                string ss13;

                //读取物品文件
                ifstream inputFile2("data.txt");

                if (!inputFile2.is_open())
                {

                    qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

                }

                getline(inputFile2, ss,'\n');//去除保存行数的一行

                int j=0;
                while (  getline(inputFile2, ss1,'\t')&&getline(inputFile2, ss2,'\t')&&getline(inputFile2, ss3,'\t')
                       &&getline(inputFile2, ss4,'\t')&&getline(inputFile2, ss5,'\t')&&getline(inputFile2, ss6,'\t')
                       &&getline(inputFile2, ss7,'\t')&&getline(inputFile2, ss8,'\t')&&getline(inputFile2, ss9,'\t')
                       &&getline(inputFile2, ss10,'\t')&&getline(inputFile2, ss11,'\t')&&getline(inputFile2, ss12,'\t')
                       &&getline(inputFile2, ss13,'\n'))
                {
                    //物品原来是已删除/待修改的状态，此处不作修改
                    if(ss13=="3"||ss13=="4")
                    {
                        j++;
                        continue;
                    }

                    //找到物品类型是修改的类型的物品，并改变状态
                    QString q1 = table->item(i, 0)->text();
                    if(std2qstr(ss1)==q1)
                    {
                        QFile file("data.txt");
                        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                            QMessageBox::critical(table, "错误", "无法打开账户文件！");
                            return;
                        }

                        // 读取所有行到内存
                        QStringList lines;
                        QTextStream in(&file);
                        while (!in.atEnd()) {
                            lines << in.readLine();
                        }

                        // 检查目标行是否存在
                        int targetLine = j+1; // 第i+2行（索引为i+1）
                        if (targetLine >= lines.size()) {
                            QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                            file.close();
                            return;
                        }

                        // 修改目标行的最后一个字符（变为待修改）
                        QString target = lines[targetLine];
                        if (!target.isEmpty()) {
                            target.replace(target.length() - 1, 1, '3');
                            lines[targetLine] = target;
                        }

                        // 写回文件
                        file.resize(0); // 清空原文件内容
                        in.seek(0);
                        for (const QString &line : lines) {
                            in << line << "\n";
                        }

                        file.close();

                    }

                    j++;
                }
                inputFile2.close();
            });


            //点击删除类型按钮
            connect(button2, &QPushButton::clicked, [this,table, i]() {
                if(i==0)
                {
                    //管理员删除“其它”类，
                    QMessageBox::information(this, "提示", "“其它”为默认类型，不可删除", QMessageBox::Ok);
                }
                else
                {
                    // 删除文件中的第 i+1 行（行号从0开始计数）

                    // 打开文件读取
                    ifstream inFile("kinds.txt");
                    if (!inFile.is_open()) {
                        qDebug() << "无法打开文件 kinds.txt";
                    }

                    // 读取所有行到 vector
                    vector<string> lines;
                    string line;
                    while (getline(inFile, line)) {
                        lines.push_back(line);
                    }
                    inFile.close();

                    // 检查索引是否有效
                    if (i < 0 || i >= static_cast<int>(lines.size()) - 1) { // 第0行是类型总数，不能删除
                        qDebug() << "无效的行索引";
                    }

                    // 删除指定行（注意：第0行是类型总数，数据行从第1行开始）
                    lines.erase(lines.begin() + i + 1);

                    // 更新第一行的类型总数
                    if (!lines.empty()) {
                        int newCount = stoi(lines[0]) - 1;
                        lines[0] = to_string(newCount);
                    }

                    // 重新写入文件
                    std::ofstream outFile("kinds.txt", std::ios::trunc);
                    if (!outFile.is_open()) {
                        qDebug() << "无法写入文件 kinds.txt";
                    }

                    for (const auto& l : lines) {
                        outFile << l << "\n";
                    }
                    outFile.close();
                    QMessageBox::information(this, "提示", "操作成功！", QMessageBox::Ok);
                    this->reviseKind();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }

                    //使用该类型的物品也要相应改变!放入其它类

                    string ss;  //去除保存行数的一行

                    //保存文件存储的13个部分的信息
                    string ss1;
                    string ss2;
                    string ss3;
                    string ss4;
                    string ss5;
                    string ss6;
                    string ss7;
                    string ss8;
                    string ss9;
                    string ss10;
                    string ss11;
                    string ss12;
                    string ss13;

                    //读取物品文件
                    ifstream inputFile2("data.txt");

                    if (!inputFile2.is_open())

                    {

                        qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

                    }

                    getline(inputFile2, ss,'\n');//去除保存行数的一行



                    int j=0;
                    while (  getline(inputFile2, ss1,'\t')&&getline(inputFile2, ss2,'\t')&&getline(inputFile2, ss3,'\t')
                           &&getline(inputFile2, ss4,'\t')&&getline(inputFile2, ss5,'\t')&&getline(inputFile2, ss6,'\t')
                           &&getline(inputFile2, ss7,'\t')&&getline(inputFile2, ss8,'\t')&&getline(inputFile2, ss9,'\t')
                           &&getline(inputFile2, ss10,'\t')&&getline(inputFile2, ss11,'\t')&&getline(inputFile2, ss12,'\t')
                           &&getline(inputFile2, ss13,'\n'))
                    {
                        QString q1 = table->item(i, 0)->text();

                        //找到物品类型是删除物品类型的物品
                        //删除原来的物品
                        if(std2qstr(ss1)==q1)
                        {
                            // 删除文件中的第 j+1 行（行号从0开始计数）

                            // 打开文件读取
                            ifstream inFile("data.txt");
                            if (!inFile.is_open()) {
                                qDebug() << "无法打开文件 data.txt";
                            }

                            // 读取所有行到 vector
                            vector<string> lines;
                            string line;
                            while (getline(inFile, line)) {
                                lines.push_back(line);
                            }
                            inFile.close();

                            // 检查索引是否有效
                            if (j < 0 || j >= static_cast<int>(lines.size()) - 1) { // 第0行是类型总数，不能删除
                                qDebug() << "无效的行索引";
                            }

                            // 删除指定行（注意：第0行是类型总数，数据行从第1行开始）
                            lines.erase(lines.begin() + j+1);

                            j--;

                            // 重新写入文件
                            std::ofstream outFile("data.txt", std::ios::trunc);
                            if (!outFile.is_open()) {
                                qDebug() << "无法写入文件 data.txt";
                            }

                            for (const auto& l : lines) {
                                outFile << l << "\n";
                            }
                            outFile.close();

                            //重新添加成其它类
                            object object1;
                            if(object1.Add("其它",ss2,ss3,ss4,ss5,ss6,ss7,"","","","",""))
                            {
                                if(ss13!="4")
                                {
                                    object1.Writefile3("data.txt"); //原来不是已删除物品，状态改为待修改
                                }
                                else
                                {
                                    object1.Writefile4("data.txt"); //原来是已删除物品，状态仍为已删除
                                }
                            }
                        }
                        j++;
                    }
                }
            });
            i++;
        }
        // 布局设置
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入表格（居中）
        layout2->addWidget(table);
        layout2->setAlignment(Qt::AlignCenter);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("物品类型表格");
        window->resize(800, 400);
        window->show();
    }

    void objectaudit()
    {
        string s;  //去除保存行数的一行

        //保存文件存储的13个部分的信息
        string s1;
        string s2;
        string s3;
        string s4;
        string s5;
        string s6;
        string s7;
        string s8;
        string s9;
        string s10;
        string s11;
        string s12;
        string s13;

        //读取物品文件
        ifstream inputFile("data.txt");

        if (!inputFile.is_open())

        {

            qDebug() << "无法打开文件 data.txt，数据读入失败\n" ;

        }

        getline(inputFile, s,'\n');//去除保存行数的一行

        int num = stringToInt(s);//保存表格行数

        QWidget *window = new QWidget; // 新建窗口

        window->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存

        QTableWidget *table = new QTableWidget(num, 15);  // 新建表格

        //表格后8列不展示，仅存储数据用
        for (int col = 7; col < 15; ++col)
        {
            table->setColumnHidden(col, true);
        }

        table->setHorizontalHeaderLabels({"物品类型","物品名称","物品所在地址","添加用户","查看详细信息", "操作1", "操作2"});

        table->verticalHeader()->setVisible(false);

        int i=0;
        int tableHigh=0;//记录表长，截短表格时用
        while (  getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
               &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')
               &&getline(inputFile, s7,'\t')&&getline(inputFile, s8,'\t')&&getline(inputFile, s9,'\t')
               &&getline(inputFile, s10,'\t')&&getline(inputFile, s11,'\t')&&getline(inputFile, s12,'\t')
               &&getline(inputFile, s13,'\n'))
        {

            //仅展示待审核物品
            if(s13=="2")
            // 设置表格内容
            {
                QString q1 = std2qstr(s1);//物品类型
                QString q2 = std2qstr(s2);//物品名称
                QString q3 = std2qstr(s4);//物品所在地址
                QString q4 = std2qstr(s5);//用户名
                QString q8 = std2qstr(s3);//物品说明
                QString q9 = std2qstr(s6);//联系人手机
                QString q10 = std2qstr(s7);//联系人邮箱
                QString q11 = std2qstr(s8);//属性1
                QString q12 = std2qstr(s9);//属性2
                QString q13 = std2qstr(s10);//属性3
                QString q14 = std2qstr(s11);//属性4
                QString q15 = std2qstr(s12);//属性5
                table->setItem(tableHigh, 0, new QTableWidgetItem(q1));
                table->setItem(tableHigh, 1, new QTableWidgetItem(q2));
                table->setItem(tableHigh, 2, new QTableWidgetItem(q3));
                table->setItem(tableHigh, 3, new QTableWidgetItem(q4));
                table->setItem(tableHigh, 7, new QTableWidgetItem(q8));
                table->setItem(tableHigh, 8, new QTableWidgetItem(q9));
                table->setItem(tableHigh, 9, new QTableWidgetItem(q10));
                table->setItem(tableHigh, 10, new QTableWidgetItem(q11));
                table->setItem(tableHigh, 11, new QTableWidgetItem(q12));
                table->setItem(tableHigh, 12, new QTableWidgetItem(q13));
                table->setItem(tableHigh, 13, new QTableWidgetItem(q14));
                table->setItem(tableHigh, 14, new QTableWidgetItem(q15));

                //添加通过物品、拒绝物品按钮、查看详细信息按钮
                QPushButton *button0 = new QPushButton("查看详细信息");
                QPushButton *button1 = new QPushButton("通过物品");
                QPushButton *button2 = new QPushButton("拒绝物品");
                table->setCellWidget(tableHigh, 4, button0);
                table->setCellWidget(tableHigh, 5, button1);
                table->setCellWidget(tableHigh, 6, button2);

                //点击查看详细信息按钮
                connect(button0, &QPushButton::clicked, [this,table, tableHigh]() {
                    string s;  //读取第一行类型数专用

                    //保存文件存储的7个部分的信息
                    string s1; //物品类型名（文件读出）
                    string s2;
                    string s3;
                    string s4;
                    string s5;
                    string s6;
                    string s7;

                    QString q41 = table->item(tableHigh, 0)->text();//物品类型名（表中读出）

                    //读取物品类型文件
                    ifstream inputFile("kinds.txt");
                    if (!inputFile.is_open())
                    {

                        qDebug() << "无法打开文件 kinds.txt，数据读入失败\n" ;

                    }

                    getline(inputFile, s,'\n');//读取第一行类型数

                    //找到该物品类型名存储位置，获取其属性
                    while (     getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                           &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\t')&&getline(inputFile, s7,'\n'))

                    {
                        if(q41==std2qstr(s1))
                            break;

                    }
                    QString q61=std2qstr(s3);
                    QString q62=std2qstr(s4);
                    QString q63=std2qstr(s5);
                    QString q64=std2qstr(s6);
                    QString q65=std2qstr(s7);


                    QWidget *window2 = new QWidget; // 新建窗口
                    window2->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存
                    QTableWidget *table2 = new QTableWidget(8, 1); // 新建表格
                    table2->setHorizontalHeaderLabels({"物品详细信息"});
                    table2->setVerticalHeaderLabels(QStringList{"联系人手机", "联系人邮箱", q61, q62,q63,q64,q65,"物品说明"});
                    QString q51 = table->item(tableHigh, 8)->text();//联系人手机
                    QString q52 = table->item(tableHigh, 9)->text();//联系人邮箱
                    QString q53 = table->item(tableHigh, 10)->text();//属性1
                    QString q54 = table->item(tableHigh, 11)->text();//属性2
                    QString q55 = table->item(tableHigh, 12)->text();//属性3
                    QString q56 = table->item(tableHigh, 13)->text();//属性4
                    QString q57 = table->item(tableHigh, 14)->text();//属性5
                    QString q58 = table->item(tableHigh, 7)->text();//物品说明
                    table2->setItem(0, 0, new QTableWidgetItem(q51));
                    table2->setItem(1, 0, new QTableWidgetItem(q52));

                    //判断是否有属性1
                    if (!q61.isEmpty()) {
                        table2->setItem(2, 0, new QTableWidgetItem(q53));
                    } else {
                        table2->setRowHidden(2, true); // 隐藏第三行
                    }

                    //判断是否有属性2
                    if (!q62.isEmpty()) {
                        table2->setItem(3, 0, new QTableWidgetItem(q54));
                    } else {
                        table2->setRowHidden(3, true); // 隐藏第四行
                    }

                    //判断是否有属性3
                    if (!q63.isEmpty()) {
                        table2->setItem(4, 0, new QTableWidgetItem(q55));
                    } else {
                        table2->setRowHidden(4, true); // 隐藏第五行
                    }

                    //判断是否有属性4
                    if (!q64.isEmpty()) {
                        table2->setItem(5, 0, new QTableWidgetItem(q56));
                    } else {
                        table2->setRowHidden(5, true); // 隐藏第六行
                    }

                    //判断是否有属性5
                    if (!q65.isEmpty()) {
                        table2->setItem(6, 0, new QTableWidgetItem(q57));
                    } else {
                        table2->setRowHidden(6, true); // 隐藏第七行
                    }



                    //物品说明从左上角顶部开始
                    QTableWidgetItem *item = new QTableWidgetItem(q58);
                    item->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                    item->setFlags(item->flags() | Qt::ItemIsEditable);
                    table2->setItem(7, 0, item);

                    table2->setColumnWidth(0, 400);  // 第一列宽度设为400像素
                    table2->setRowHeight(7, 200); // 第八行高度设为400像素

                    QHBoxLayout *layout3 = new QHBoxLayout;
                    //布局加入表格
                    layout3->addWidget(table2);

                    //界面展示布局，并设置名称、大小
                    window2->setLayout(layout3);
                    window2->setWindowTitle("详细信息");
                    window2->resize(500, 600);
                    window2->show();
                });


                //点击通过物品按钮，物品状态改为已通过
                connect(button1, &QPushButton::clicked, [this,table, i]() {

                    //打开文件
                    QFile file("data.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i+1; // 第i+2行（索引为i+1）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为已通过）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '1');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();

                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "通过物品成功");

                    //刷新数据
                    this->objectaudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });

                //点击拒绝物品按钮，物品状态改为待修改
                connect(button2, &QPushButton::clicked, [this,table, i]() {

                    //打开文件
                    QFile file("data.txt");
                    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                        QMessageBox::critical(table, "错误", "无法打开账户文件！");
                        return;
                    }

                    // 读取所有行到内存
                    QStringList lines;
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        lines << in.readLine();
                    }

                    // 检查目标行是否存在
                    int targetLine = i+1; // 第i+2行（索引为i+1）
                    if (targetLine >= lines.size()) {
                        QMessageBox::critical(table, "错误", "目标行超出文件范围！");
                        file.close();
                        return;
                    }

                    // 修改目标行的最后一个字符（改为待修改）
                    QString target = lines[targetLine];
                    if (!target.isEmpty()) {
                        target.replace(target.length() - 1, 1, '3');
                        lines[targetLine] = target;
                    }

                    // 写回文件
                    file.resize(0); // 清空原文件内容
                    in.seek(0);
                    for (const QString &line : lines) {
                        in << line << "\n";
                    }

                    file.close();

                    // 弹出成功消息
                    QMessageBox::information(table, "操作成功", "拒绝物品成功");

                    //刷新数据
                    this->objectaudit();

                    //关闭整个窗口
                    QWidget* topLevelWindow = table->window();
                    if (topLevelWindow && topLevelWindow != this) {
                        topLevelWindow->close();
                        topLevelWindow->deleteLater();
                    }


                });
                tableHigh++;
            }
            i++;

        }

        // 布局设置
        table->setRowCount(tableHigh);
        QLabel *label1 = new QLabel("共有" + QString::number(tableHigh) + "个物品等待审核");
        label1->setFixedWidth(120);
        QHBoxLayout *layout2 = new QHBoxLayout;

        //布局加入表格、标签
        layout2->addWidget(label1);
        layout2->addWidget(table);

        //界面展示布局，并设置名称、大小
        window->setLayout(layout2);
        window->setWindowTitle("软件物品表格");
        window->resize(900, 600);
        window->show();
    }

};




// 主窗口类，继承自QWidget
class MainWindow : public QWidget {
    Q_OBJECT  // Qt宏，启用元对象系统
public:
    // 构造函数，初始化主窗口界面
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("物品复活软件");  // 设置窗口标题
        setFixedSize(800, 400);  // 固定窗口大小

        // 创建垂直布局管理器
        QVBoxLayout *layout = new QVBoxLayout(this);
        setLayout(layout);

        // 创建登录按钮
        QPushButton *LoginButton = new QPushButton("登录");
        LoginButton->setFixedWidth(200);
        LoginButton->setFixedHeight(50);
        layout->addWidget(LoginButton);  // 添加到布局

        // 创建关闭应用按钮
        QPushButton *closeButton = new QPushButton("关闭应用");
        closeButton->setFixedWidth(200);
        closeButton->setFixedHeight(50);
        layout->addWidget(closeButton);  // 添加到布局

        // 居中
        setLayout(layout);
        layout->setAlignment(Qt::AlignCenter);

        // 连接登录按钮点击信号到显示对话框的槽函数
        connect(LoginButton, &QPushButton::clicked, this, &MainWindow::showLoginDialog);

        // 连接关闭按钮点击信号到窗口关闭槽函数
        connect(closeButton, &QPushButton::clicked, this, &MainWindow::close);


    }

    //返回登录成功状态
    int getsuccess()
    {
        return success;
    }

private:
    // 显示输入对话框的槽函数
    int success=2; //保存是否登录成功，2不成功，1成功（普通），0成功（管理员）
    bool showLoginDialog() {
        LoginDialog dialog(this);  // 创建登录对话框实例
        // 显示对话框并等待用户操作
        if (dialog.exec() == QDialog::Accepted) {

            // 如果用户点击确定，获取输入内容（账号与密码）
            QString input1 = dialog.getInput1();
            QString input2 = dialog.getInput2();
            string id = qstr2std(input1);
            string password = qstr2std(input2);

            // 在控制台输出用户输入（调试用）
            qDebug() << "用户输入 账号:" << id.c_str()<< "密码" << password.c_str();

            //核对账号密码信息
            string s;  //去除多余字符专用

            //保存文件存储的6个部分的信息
            string s1;
            string s2;
            string s3;
            string s4;
            string s5;
            string s6;

            //读取账户文件
            ifstream inputFile("account.txt");
            if (!inputFile.is_open())
            {
                qDebug() << "无法打开文件 account.txt，数据读入失败\n" ;
            }
            getline(inputFile, s,'\n');//去除文件中第一个回车


            while (getline(inputFile, s1,'\t')&&getline(inputFile, s2,'\t')&&getline(inputFile, s3,'\t')
                   &&getline(inputFile, s4,'\t')&&getline(inputFile, s5,'\t')&&getline(inputFile, s6,'\n'))
            {
                //账号密码正确，但账号待审核
                if((s1==id)&&s2==(password)&&s6=="2")
                {
                    QMessageBox::information(this, "提示", "您的账号还没有审核完毕，请耐心等待。", QMessageBox::Ok);
                    return 1;
                }

                //账号密码正确，但账号已拒绝
                if((s1==id)&&s2==(password)&&s6=="3")
                {
                    QMessageBox::information(this, "提示", "您的账号被管理员拒绝。", QMessageBox::Ok);
                    return 1;
                }

                //账号密码正确，但账号被封禁
                if((s1==id)&&s2==(password)&&s6=="4")
                {
                    QMessageBox::information(this, "提示", "您的账号被管理员封禁。", QMessageBox::Ok);
                    return 1;
                }

                //账号密码正确，但账号被删除
                if((s1==id)&&s2==(password)&&s6=="5")
                {
                    QMessageBox::information(this, "提示", "您的账号被管理员永久删除。", QMessageBox::Ok);
                    return 1;
                }

                //账号密码正确，且账号为正式用户
                if((s1==id)&&s2==(password)&&s6=="1")
                {
                    qDebug()<<"登录成功，欢迎回来！\n";
                    success=1;
                    ID=s1;//记录用户账号
                    close();
                    inputFile.close();
                    return 1;
                    //账号密码正确，进入软件(普通用户模式)
                }
                //账号密码正确，且账号为管理员
                if((s1==id)&&s2==(password)&&s6=="0")
                {
                    qDebug()<<"管理员你好！\n";
                    success=0;
                    close();
                    inputFile.close();
                    return 1;
                    //账号密码正确，进入软件(管理员模式)
                }
            }

            //其余情况：账号或密码错误
            qDebug()<<"账号或密码错误，请重试！";
            QMessageBox::critical(
                nullptr,
                "错误",
                "账号或密码错误，请重试！",
                QMessageBox::Ok
                );
            inputFile.close();
            return 0;
        }
    }
};




// 程序主函数
int main(int argc, char *argv[]) {


    // 创建QApplication实例，管理应用程序控制流和设置
    QApplication a(argc, argv);

    // 创建主窗口实例
    MainWindow window;
    // 显示主窗口
    window.show();
    a.exec();
    //普通用户模式，打开第二窗口
    if(window.getsuccess()==1)
    {
        window.close();
        SecondWindow Window2;
        Window2.show();
        a.exec();
    }

    //管理员模式，打开管理员窗口
    if(window.getsuccess()==0)
    {
        window.close();
        AdministratorWindow Window3;
        Window3.show();
        a.exec();
    }
    // 进入主事件循环，等待用户操作
    return a.exec();
}

// 包含MOC（Meta-Object Compiler）生成的代码，启用信号槽机制
#include "main.moc"


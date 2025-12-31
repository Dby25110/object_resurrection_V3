#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <sstream>
#include <QWidget>


using namespace std;


bool removeSpecificLine(const string& filename, int lineNumber);

//账户类，用于保存用户账号及密码信息
class Account : public QWidget
{
private:
    string a; // 账号名称
    string b; // 密码;
    string c; //住址
    string d; //联系人电话
    string e; //联系人邮箱
public:
    Account() = default;//默认构造函数

    //把信息写入文件中存储
    bool Writefile(const string& filename) const
    {
        ofstream outputFile(filename,ios::app); //通过std::ios::app标志位指定追加写入模式，此时所有写入操作均在文件末尾进行

        if (outputFile.is_open())
        {
            outputFile <<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<'\t'<<"2"<<endl;
            outputFile.close();
        } else
        {
            return 0;
        }
        return 1;
    }



    //添加账号信息函数，两次输入的密码一致，且输入的字符串长度符合要求，返回1；其余情况返回0
    bool Add(string sa,string sb,string sc,string sd,string se,string sf)
    {
        //用户名
        if(sa.length()>20)
        {
            QMessageBox::information(this, "提示", "您输入的用户名太长，字符数大于20，请重试!", QMessageBox::Ok);
            return 0;
        }

        //密码
        if(sb.length()>20)
        {
            QMessageBox::information(this, "提示", "您输入的密码字符数大于20，密码太长，请重试！", QMessageBox::Ok);
            return 0;
        }

        //确认密码
        if(sd.length()>100)
        {
            QMessageBox::information(this, "提示", "您输入的住址太长，字符数大于100，请重试!", QMessageBox::Ok);
            return 0;
        }

        //联系人电话
        if(se.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的联系人电话太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //联系人邮箱
        if(sf.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的联系人邮箱太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }


        //赋属性值
        a=sa;
        c=sd;
        d=se;
        e=sf;

        if(sb==sc)
        {
            b=sb;
            return 1;
        }                 //两次输入的密码一致
        else return 0;                            //两次输入的密码不一致

    }

    //返回用户账号名称
    string Return_a() const
    {
        return a;
    }

};

//替换第一行的值
void replaceFirstLine(const std::string& filename, int number) {
    // 读取整个文件
    std::ifstream inFile(filename);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    // 丢弃首行并重组内容
    std::string content = buffer.str();
    size_t pos = content.find('\n');
    if (pos != std::string::npos) {
        content = std::to_string(number) + content.substr(pos);
    } else {  // 文件只有一行的情况
        content = std::to_string(number);
    }

    // 写回文件
    std::ofstream outFile(filename);
    outFile << content;
}

#endif // ACCOUNT_H

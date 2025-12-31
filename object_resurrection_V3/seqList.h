#ifndef SEQLIST_H
#define SEQLIST_H


#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <sstream>
#include <QWidget>


using namespace std;




//物品类，用于保存某一物品信息


class object:public QWidget {
private:
    string a; // 物品类型
    string b; // 物品名称
    string c; // 物品说明
    string d; // 物品所在地址
    string id; // 联系人账号信息
    string e; // 联系人手机
    string f; // 联系人邮箱
    string s1; // 属性1（如有）
    string s2; // 属性2（如有）
    string s3; // 属性3（如有）
    string s4; // 属性4（如有）
    string s5; // 属性5（如有）
public:
    object() = default;//默认构造函数

    //重载构造函数，为12个私有字符串类元素赋值
    bool Add(string s11,string s12,string s13,string s14
             ,string s15,string s16,string s17,string s18
             ,string s19,string s20,string s21,string s22)
    {
        // 物品名称长度限制
        if(s12.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的物品名称太长，字符数大于20，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 物品说明长度限制
        if(s13.length()>1000)
        {
            QMessageBox::information(this, "提示", "您输入的物品说明太长，字符数大于1000，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 物品地址长度限制
        if(s14.length()>200)
        {
            QMessageBox::information(this, "提示", "您输入的物品所在地址太长，字符数大于200，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 联系人手机长度限制
        if(s16.length()>20)
        {
            QMessageBox::information(this, "提示", "您输入的联系人手机太长，字符数大于20，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 联系人邮箱长度限制
        if(s17.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的联系人邮箱太长，字符数大于50，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 属性1长度限制
        if(s18.length()>500)
        {
            QMessageBox::information(this, "提示", "您输入的属性内容太长，字符数大于500，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 属性2长度限制
        if(s19.length()>500)
        {
            QMessageBox::information(this, "提示", "您输入的属性内容太长，字符数大于500，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 属性3长度限制
        if(s20.length()>500)
        {
            QMessageBox::information(this, "提示", "您输入的属性内容太长，字符数大于500，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 属性4长度限制
        if(s21.length()>500)
        {
            QMessageBox::information(this, "提示", "您输入的属性内容太长，字符数大于500，请重试！", QMessageBox::Ok);
            return 0;
        }

        // 属性5长度限制
        if(s22.length()>500)
        {
            QMessageBox::information(this, "提示", "您输入的属性内容太长，字符数大于500，请重试！", QMessageBox::Ok);
            return 0;
        }

        //赋属性值
        a=s11;
        b=s12;
        c=s13;
        d=s14;
        id=s15;
        e=s16;
        f=s17;
        s1=s18;
        s2=s19;
        s3=s20;
        s4=s21;
        s5=s22;
        return 1;
    }

    //把信息写入文件中存储（写成待审核状态）
    bool Writefile(const string& filename) const
    {
        ofstream outputFile(filename,ios::app); //通过std::ios::app标志位指定追加写入模式，此时所有写入操作均在文件末尾进行

        if (outputFile.is_open())
        {
            outputFile <<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'
                       <<id<<'\t'<<e<<'\t'<<f<<'\t'<<s1<<'\t'
                       <<s2<<'\t'<<s3<<'\t'<<s4<<'\t'<<s5<<'\t'
                       <<"2"<<endl;
            outputFile.close();
        }
        else
        {
            return 0;
        }
        return 1;
    }

    //把信息写入文件中存储（写成待修改状态）
    bool Writefile3(const string& filename) const
    {
        ofstream outputFile(filename,ios::app); //通过std::ios::app标志位指定追加写入模式，此时所有写入操作均在文件末尾进行

        if (outputFile.is_open())
        {
            outputFile <<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'
                       <<id<<'\t'<<e<<'\t'<<f<<'\t'<<s1<<'\t'
                       <<s2<<'\t'<<s3<<'\t'<<s4<<'\t'<<s5<<'\t'
                       <<"3"<<endl;
            outputFile.close();
        }
        else
        {
            return 0;
        }
        return 1;
    }

    //把信息写入文件中存储（写成已删除状态）
    bool Writefile4(const string& filename) const
    {
        ofstream outputFile(filename,ios::app); //通过std::ios::app标志位指定追加写入模式，此时所有写入操作均在文件末尾进行

        if (outputFile.is_open())
        {
            outputFile <<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'
                       <<id<<'\t'<<e<<'\t'<<f<<'\t'<<s1<<'\t'
                       <<s2<<'\t'<<s3<<'\t'<<s4<<'\t'<<s5<<'\t'
                       <<"4"<<endl;
            outputFile.close();
        }
        else
        {
            return 0;
        }
        return 1;
    }
};

#endif // SEQLIST_H

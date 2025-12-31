#ifndef KINDS_H
#define KINDS_H



using namespace std;

//bool removeSpecificLine(const string& filename, int lineNumber);

//账户类，用于保存用户账号及密码信息
class Kinds : public QWidget
{
private:
    string a; //类型名称
    string b; //属性1
    string c; //属性2
    string d; //属性3
    string e; //属性4
    string f; //属性5
    string n;//有效属性的数量
public:
    Kinds() = default;//默认构造函数

    //把信息写入文件中存储
    bool Writefile(const string& filename) const
    {
        ofstream outputFile(filename,ios::app); //通过std::ios::app标志位指定追加写入模式，此时所有写入操作均在文件末尾进行

        if (outputFile.is_open())
        {
            outputFile <<a<<'\t'<<n<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<'\t'<<f<<endl;
            outputFile.close();
        } else
        {
            return 0;
        }
        return 1;
    }



    //添加物品类型信息函数
    bool Add(string sa,string sb,string sc,string sd,string se,string sf)
    {
        //类型名长度限制
        if(sa.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的类型名称太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //属性1长度限制
        if(sb.length()>50)
        {
            QMessageBox::information(this, "提示", "您输入的属性1太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //属性2长度限制
        if(sc.length()>50)
        {
            QMessageBox::information(this, "提示",  "您输入的属性2太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //属性3长度限制
        if(sd.length()>50)
        {
            QMessageBox::information(this, "提示",  "您输入的属性3太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //属性4长度限制
        if(se.length()>50)
        {
            QMessageBox::information(this, "提示",  "您输入的属性4太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //属性5长度限制
        if(sf.length()>50)
        {
            QMessageBox::information(this, "提示",  "您输入的属性5太长，字符数大于50，请重试!", QMessageBox::Ok);
            return 0;
        }

        //赋属性值
        a=sa;
        b=sb;
        c=sc;
        d=sd;
        e=se;
        f=sf;

        //记录非空属性的值
        int num = 0;
        if (!b.empty()) num++;
        if (!c.empty()) num++;
        if (!d.empty()) num++;
        if (!e.empty()) num++;
        if (!f.empty()) num++;

        //转换为字符串型
        if (num==0) n="0";
        if (num==1) n="1";
        if (num==2) n="2";
        if (num==3) n="3";
        if (num==4) n="4";
        if (num==5) n="5";

        return 1;

    }

    //返回类型名称
    string Return_a() const
    {
        return a;
    }

};

#endif // KINDS_H

#ifndef CONVERT_H
#define CONVERT_H

//字符串重排序，空的换到最后（针对5五个属性）
void sortStrings(QString &q4, QString &q5, QString &q6, QString &q7, QString &q8) {
    // 创建包含所有字符串的列表
    QStringList list = {q4, q5, q6, q7, q8};
    // 分离非空字符串
    QStringList nonEmpty;
    // 分离空字符串
    QStringList empty;
    // 遍历原始列表
    for (const auto &str : list) {
        // 检查字符串是否为空
        if (str.isEmpty()) {
            // 添加到空字符串列表
            empty.append(str);
        } else {
            // 添加到非空字符串列表
            nonEmpty.append(str);
        }
    }
    // 合并非空和空字符串列表
    list = nonEmpty + empty;
    // 更新原始参数引用
    q4 = list[0];
    q5 = list[1];
    q6 = list[2];
    q7 = list[3];
    q8 = list[4];
}


// QString 转 std::string
std::string qstr2std(const QString& qstr) {
    QByteArray data = qstr.toUtf8();  // 使用 UTF-8 转换
    return std::string(data);
}

// std::string 转 QString
QString std2qstr(const std::string& str) {
    return QString::fromUtf8(str);  // 使用 UTF-8 转换
}

// string 转 int（最大99999）
int stringToInt(const std::string& s) {
    if (s.length() > 5) {
        throw std::invalid_argument("字符串长度超过5个字符");
    }
    int result = 0;
    for (char c : s) {
        if (c < '0' || c > '9')
        {
            throw std::invalid_argument("字符串包含非数字字符");
        }
        result = result * 10 + (c - '0');
    }
    return result;
}

#endif // CONVERT_H

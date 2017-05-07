#include <iostream>
#include <vector>

using namespace std;

int main(void){
    // 创建
    vector<int> tmp = {1, 2, 3};
    // 得到向量中的元素
    cout << tmp.at(0) << endl;
    cout << tmp[0] << endl;
    // 添加元素
    tmp.push_back(4);
    tmp.push_back(5);
    // 得到数组头和最后一个单元+1的指针
    tmp.begin();
    tmp.end();
    // 删除数据 c.erase(pos) 删除[beg, end]区间的数据 c.erase(beg, end)
    for(int i : tmp){
        cout << i << " ";
    }
    cout << endl;

    // 当前 vector 分配的大小
    cout << tmp.capacity() << endl;
    // 判断当前的 vector 是否为空
    cout << tmp.empty() << endl;


    // C++ 中的结构体，可以有构造函数，所以可以使用 new 的方式，与 C 的构造和初始化的不同
    // 另外查看下 C++ 的引用和指针，感觉自己还不够理解
}
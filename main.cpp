// YYD, c.biancheng.net, 17/07/2015
// C++是由AT&T Bell（贝尔）实验室的Bjarne Stroustrup于20世纪80年代初在C语言的基础上开发成功的。
//
/* 如何装一个额外的包：
 1 下载一个包，然后找到它的/include，放到xcode的header serach path里面，注意要是combined下的, /lib 放到lib search path里面. 如果添加没用，那就用cmd里面的g++, gcc -o xx.cpp exename -I /usr/local/include
 2 用这个包时如果有一系列的link flag，那再cmd里面先找到这些link flag对应的具体的库，然后复制到linking下面的other linking flag里面去
 */

// 函数若在定义前被使用，那么必须在被使用的地方之前加上声明,给与函数原型
// .cpp文件编译为二进制的.obj/.o,检查语法,系统提供的“连接程序(linker)”将一个程序的所有目标程序和系统的库文件连接起来，最终形成一个可执行的二进制文件.exe

// 在Visual C++ 6.0中，对float提供6位有效数字，对double提供15位有效数字
// signed int，4个字节，能存储的最大值为2^15-1，即32767，最小值为-32768(+1并且取负)。
// unsighed int，能存储的最大值为2^16-1，即65535，最小值为0。它存储正数的范围比用signed时要大一倍

// 常量
// 整形常量本质上是signed的，常量后面加l/L就是long型常量，以0开头8进制，以0x开头16进制
// 浮点型常量统一按float处理，8个字节，除非用F/f声明单精度，4个字节，或者双精度L/l,12个字节，浮点类型存放的方法在内存里是 符号+数字+指数，数字部分0.2xxx标准形式。对于以指数形式表示的数值常量，也都作为双精度常量处理。
// 字符常量:占一个字节，'a','A','\n',以ascii码存，本质上就是整形常量，可以直接相互赋值，小写字母比大写字母大32
// 字符串常量： "abc"最后有一个'\0', 字符串可以用\表示割开续行，与第二行的内容没有空格
// 符号常量： #define Price 30 ,没有分号

// 变量：
//允许在定义变量时对它赋予一个初值，这称为变量初始化. 静态存储变量和外部变量的初始化是在编译阶段完成的，其他初始化都在执行阶段完成
// 变量和常量之间有一个桥梁：const，必须在定义时初始化
// const vs define:  define指示用一个符号代替一个字符串，本身没有类型和存储单元， const定义完是一个变量，有类型和存储单元


// ++,--前缀用的是向右结合，后缀用的是向左结合，不同于算术符号用的是向左结合。http://c.biancheng.net/cpp/biancheng/view/2079.html. ++ --不可以用于常量，只可以用于变量

// 任何有float参与的计算都会先转换为double
// 在强制类型转换时，得到一个所需类型的中间变量，但原来变量的类型未发生变化.将浮点型数据(包括单、双精度)赋给整型变量时，舍弃其小数部分。将一个int、short或long型数据赋给一个char型变量，只将其低8位原封不动地送到char型变量(发生截断).
// x %= y+3 -> x = x%(y+3)(不要错认为x=x%y+3)


// 普通main函数外面的变量只是该文件中的全局变量，定义跨文件的全局变量时，要放在.cpp中，不能放在.h中是因为怕多个文件调用.h从而导致重复定义。但是在.h文件中要用extern 来告诉调用的文件，该变量是一个跨文件的全局变量。
/* 
 filel.cpp
 extern int a,b;
 int main()
 {
 cout<<a<<","<<b<<end!;
 return 0;
 }

 file2.cpp
 int a=3,b=4; // 如果a,b申明是static那么即便Extern int a, b那么file1也是用不了的

 */
// 对于函数来说，不需要extern在包含.h中也能跨文件调用，如果只想在本文件内调用可以用static


// c++中赋值语句本身又是运算符，会返回一个被赋值的值

// 在定义流对象时，系统会在内存中开辟一段缓冲区，用来暂存输入输出流的数据。在执行cout语句时，先把数据顺序存放在输出缓冲区中，直到输出缓冲区满或遇到endl(或'\n'，ends，flush)为止，此时将缓冲区中已有的数据一起输出，并清空缓冲区。就像是python 里面的 -u,立即清空缓存

// cin不可以录入回车和空格，它们将被跳过。如果想将空格字符或回车换行符，用getchar函数。
// putchar , 给以输出整数ascii码对应的字符，也可以输出字符
// getchar函数得到的字符的ascii码，可以赋给一个字符变量或整型变量，没赋值前是整数。getchar可以吸收任何字符，在有多个getchar时要连续输入，然后再按回合

// 关系运算符，==优先级最低，a>b==c等效于(a>b)==c,逻辑运算符优先级比算术低，先算再比最后赋值
// 在C++中，整型数据可以出现在逻辑表达式中，在进行逻辑运算时，根据整型数据的值是0或非0，把它作为逻辑量假或真，然后参加逻辑运算。

// 注意if与else的配对关系。else总是与它上面最近的、且未配对的if配对, 如果有的语句没有else，一定要用{}隔开
// 条件运算符优先级比赋值高： max=(a>b)?a:b
//  大小写转换：ch=(ch>='A' && ch<='Z')?(ch+32):ch

// switch-case:本质上是一个if-else的夸大版。各个case和default的出现次序不影响执行结果, 在执行switch语句时，根据switch表达式的值找到与之匹配的case子句，就从此case子句开始执行下去，不再进行判断
// switch(c){case 0:, case 1: }
// do{}while();  这里这个分号不能漏
// for(1;2;3)上来会先执行1再判断2
// c++中凡用while循环能完成的，用for循环都能实现,但是R python里面for 循环不带条件控制，只是计数循环，所以不可取代while
// break语句只能用于循环语句和switch语句内，不能单独使用或用于其他语句中。

// 函数
// 在C++面向对象的程序设计中，主函数以外的函数大多是被封装在类中的
//  在定义函数时指定的形参，在未出现函数调用时，它们并不占内存中的存储单元，因此称它们是形式参数或虚拟参数
// 实参表列可以没有，但括号不能省略,return语句后面的括号可以要，也可以不要
// 所谓函数声明(declare)，就是在函数尚在未定义的情况下，事先将该函数的有关信息通知编译系统，以便使编译能正常进行。以便在对包含函数调用的语句进行编译时，据此对其进行对照检查。在函数声明中也可以不写形参名，而只写形参的类型，这叫函数原型
// inline函数，内置函数中不能包括复杂的控制语句，如循环语句和switch语句。是否真的inline由编译器决定
// 函数重载的本质:形参不同。重载函数的参数个数、参数类型或参数顺序3者中必须至少有一种不同，函数返回值类型可以相同也可以不同，一个函数不能既作为重载函数，又作为有默认参数的函数
// 函数默认值必须在声明或者定义先出现的地方赋值，并且是放右边
// 模板函数： 函数体相同，个数相同，类型不同，节约重载时要不停重复函数体的麻烦
// 函数不可以嵌套定义，但是可以嵌套调用，python可以嵌套定义



// 作用域是空间角度，是否可见，存储器是时间角度，是否存在，分静态和动态，静态包括（static+全局变量），占固定存储单元，静态变量在编译时赋值，默认值0(全局变量在声明时要用extern)，程序执行完时释放， 动态分配占的地址空间不固定，比如形参，函数中的局部变量，及auto声明的变量，动态变量在函数调用时赋值，默认值不确定，在函数执行完释放

// 寄存器变量，register int a; 在程序中定义寄存器变量对编译系统只是建议性(而不是强制性)的。当今的优化编译系统能够识别使用频繁的变量，自动地将这些变量放在寄存器中。

// 对局部变量用static声明，使该变量在本函数调用结束后不释放，整个程序执行期间始终存在，但外面看不见,使其存储期为程序的全过程。
// 全局变量用static声明，则该变量的作用域只限于本文件模块(即被声明的文件中)。static + 函数该函数不可以被外部的cpp调用

// 函数调用和include的关系：函数本质上是外部的，即便不include,统一工程下的cpp文件函数可以互相调用，但是需要申明，可以用Extern声明函数原型(extern可以省略)，编译器随后在下文或者其他文件中寻找，head文件就是把一系列函数原型放在一起，免去了一个个申明的麻烦
// 头文件中有：1 各种声明 2 inline, 全局变量，宏，const变量的定义

// 声明 vs 定义
// 只要出现Extern就一定是声明。
// 对于函数来说，声明和定义很清晰，对于变量来说，声明包括定义，就看是否建立存储空间，int a 是定义性声明，但是 extern int a 就是引用性声明


// 预处理：本质上不是c++语言的一部分，他们以#开头，没有分号结尾， #if #else #endif 可以放在正文当中

// 数组
/*
 
 C++不允许对数组的大小作动态定义，即数组的大小不依赖于程序运行过程中变量的值

 C++实际上只把形参数组名作为一个指针变量来处理,如果用二维数组名作为实参和形参，在对形参数组声明时，必须指定第二维(即列)的大小，且应与实参的第二维的大小相同 

 数组在不同指针的情况下不允许整个赋值，更加上数组名是常量

 字符串和字符数组
 char str[10]=″China″; 
 char str[]={'I',' ','a','m',' ','h','a','p','p','y','\0'};
 
 字符串以\0为结束标志，如果一个字符数组中包含一个以上′\0′，则遇第一个′\0′时输出就结束。
 strcat(char[], const char[])
 将第二个字符数组中的字符串连接到前面字符数组的字符串的后面,第一个字符串改变
 
 strcpy(char[], const char[]); 字符串的赋值
 它的作用是将第二个字符数组中的字符串复制到第一个字符数组中去，将第一个字符数组中的相应字符覆盖
 
 strlen 检查长度，不包括\0
 
 C++的字符串类型string
 1 string可以直接赋值，不需要strcpy， str1 = str2, 也不需要考虑长度（本质上是指针）, 大小可以用>=比较
 2 可以更改某个元素的值，这个python不行
 3 可以用+号连接
 
 string name[5] 表示的就是5个字符串，不是长度为5的字符数组，实际存放的是每个字符串的地址
 */


// 指针
/*
 1 指针变量不可以指向常量 3, const int, 一定要通过一个变量的取地址
 
 2 在用指针作为函数形参时，需要注意的是，函数内部应该改变的是指针所指向的值，对指针本身的改变并不能传送到函数外面去，因为地址本身是值传递
 
 3 *p++ = (*p++) 是先取*p,再p++
 4 数组名代表数组首元素的地址，并且是常量，int a[10], a++是不允许的
 5 int a[3][4], int *p = a[0], p+1 不是下一行的4个元素，这里p指向a[0][1]， int (*p)[4]=&a[0], 这时p才是，一定要搞清楚当前指针是一个一维指针还是个2维指针
 5.5 int **w w是一个指向指针的指针，普通的二维数组里面存的是元素，并不是指针，数组名只是元素的指针，并不是指针的指针，所以不可赋值

 6 int * fun(int,int) 返回一个int指针
   int (*func)(int,int) 定义一个函数指针
    int *a[], a是一个指针数组，a本身是指针的指针
 7 iostream里面有NULL=0的定义，所以可以用p=NULL
 8 传引用比传指针更加好用，因为传指针需要开辟额外的存放指正的单元，传引用只需在形参前加&，系统自动传入实参的地址
 */



/* 结构体
 
 结构体可以直接赋值，student2 = student1;
 嵌套结构体成员要逐层访问student1.birthday.month
 对齐原则：
 公式1:前面的地址必须是后面的地址正数倍,不是就补齐
 公式2:整个Struct的地址必须是最大字节的整数倍
 如果用结构体指针，那么可以p->num调用元素，->优先级比++高
 
 不用new开辟的stuct链表是静态链表，内存连续开辟

 共用体union: 把几个成员揉到一段内存中
 */


// new 是运算符，不是函数
// new在开辟数组时不可以初始化,所以不能开辟const类型的

// 枚举常量：enum color{red,yellow,blue,white,black}; color col;
// col可以用在switch里面，每种可能都会被附上0,1,2..但是整数不可以赋值给col

// typedef int (*POINTER)( )  //声明POINTER为指向函数的指针类型，函数返回整型值. typedef可以声明各种类型名，但不能用来定义变量
/* 定义的方法： 先按定义变量的方法写出定义语句（如int i;）。
将变量名换成新类型名（如将i换成COUNT）。
在最前面加typedef(如typedef int COUNT)。
然后可以用新类型名去定义变量。
*/


/* 类
 1 类在外定义成员函数时一定要加上类名::func, 如果仅有::说明是全局作用域的函数
 2 如果在类体中定义的成员函数中不包括循环等控制结构，C++系统会自动将它们作为内置(inline)函数来处理。如果在类外，则要用Inline,并且定义要和类的声明放在一起。
 3 C++编译系统正是这样做的，因此每个对象所占用的存储空间只是该对象的数据部分所占用的存储空间，而不包括函数代码所占用的存储空间。this指针帮助区别不同的数据
 4 类的定义和声明分开的原因: 防止常用的类多次被编译，同时接口于实现要分离，开发商把用户所需的各种类的声明按类放在不同的头文件中，同时对包含成员函数定义的源文件进行编译，得到成员函数定义的目标代码。软件商向用户提供这些头文件和类的实现的目标代码(不提供函数定义的源代码)。
 5 如果一个类中所有的成员都是公用的，则可以在定义对象时对数据成员进行初始化，如果类中有private或protected的成员，就不能用这种方法初始化，要用构造函数
 6 如果要调用默认构造函数，不要加括号，这和没有参数的函数要加括号不同
 7 构造函数如果有默认值，要放在声明里面，如果一个类的构造函数是全带默认值的情况，那么构造函数就不能再重载，会有二义性
 8 析构函数只能有一个，但可以是虚的，静态内存上的对象，比如static/全局对象，在main函数结束时释放，动态局部对象函数结束时释放，new建立的动态对象需要手动释放
 9 类的数组初始化时要用这样定义：
 Student Stud[3]={ //定义对象数组
 Student(1001,18,87),  //调用第1个元素的构造函数，为它提供3个实参
 Student(1002,19,76),  //调用第2个元素的构造函数，为它提供3个实参
 Student(1003,18,72)  //调用第3个元素的构造函数，为它提供3个实参
 };
 
 10 函数指针： typedef void(*Fun)(int,int);
              Fun pFun=NULL;
             pFun=&min;  
             pFun(1,2);
   指向成员函数的指针：数据类型名 (类名::*指针变量名)(参数表列); 要加一个类名，和不同函数指针不一样的地方
   void (Time::*p2)( ); p2=&Time::get_time;
   调用时要 (对象.*p2)() 定义时用类名定义，因为类的函数共享一块存储区，但是调用时要用对象，并且*号不可以少，和普通的函数指针不一样
 
 函数名和指针的关系：
 函数名是函数实体的代表，不是地址的代表。从函数到指针的隐式转换是函数名在表达式中的行为，就是说，这个转换仅在表达式中才会发生。由于C++规定，非静态成员函数的左值不可获得，因此非静态成员函数不存在隐式左值转换，即不存在像常规函数那样的从函数到指针的隐式转换，所以必须在非静态成员函数前使用&操作符才能获得地址。
 
 数组名和指针的关系：
 表达式中的数组名被编译器当作一个指向该数组第一个元素的指针。对数组名取一次地址还是数组第一个元素的地址。

   void Time::*(p2()) p2是一个返回void型指针的time类里的一个函数，本质上是一个函数
 
 11 如果一个对象被声明为常对象，则不能调用该对象的非const型的成员函数（除了由系统自动调用的隐式的构造函数和析构函数）， 但即便是成员函数后面加了一个const,它仍然可以修改mutbale的变量
 12 如果类有常量成员，只能通过构造函数的初始化列表对常数据成员进行初始化
 13 如果形参是const 指针，那么可以传入普通指针，目的在于不希望该函数修改实参，如果非const，那么不可以传入const指针，因为非const指针不可以指向const对象

 14 如果类成员中有动态分配的指针，那么要重载赋值函数
 15 拷贝构造 vs 赋值函数： 拷贝构造是定义一个新的对象，赋值不是， 系统默认的赋值和拷贝构造都是简单的拷贝对象中的数据，如果数据中有动态分配的要特别小心。 拷贝构造的两大用处，实参传形参，函数返回值
 16 Box box2(box1) == Box box2=box1, 等价，都是初始化
 17 静态数据成员不属于某一个对象，而是属于类的，但类的对象可以引用它。
    静态数据成员是在所有对象之外单独开辟空间，不算在对象上。只要在类中定义了静态数据成员，即使不定义对象，也为静态数据成员分配空间，它可以被引用。静态数据成员是在程序编译时被分配空间的，到程序结束时才释放空间。静态数据成员的作用域和类一致，并不等同于全局变量。
    静态数据成员只能在类外初始化，并且不可以放在初始化列表里面初始化。
   非静态成员函数有this指针，而静态成员函数没有this指针。由此决定了静态成员函数不能访问本类中的非静态成员。
 18 普通函数声明为友元时，友元函数不属于当前类和对象，所以在定义的时候不必用类名：：func, 但是如果这个友元函数是其他类的成员函数时，就要声明，friend void Time::display(Date &);，这里的time::不可以省略
 19 友元类就是友元类B中的所有函数都是A类的友元函数，在A类的定义体中用以下语句声明B类为其友元类：
     friend B; 但这并不等于A类也是B类的友元类
 20 模板类，
 */
template <class numtype> //声明一个模板，虚拟类型名为numtype
class Compare //类模板名为Compare
{
    public :
    Compare(numtype a,numtype b)
    {
        x=a;y=b;
    }
    numtype max( );

    numtype min( )
    {
        return (x<y)?x:y;
    }
    private :
    numtype x,y;
};

template <class numtype>
numtype Compare<numtype>::max( ) //不能用compare::
{
    return (x>y)?x:y;
}

//调用
Compare <int> cmp(4,7);

//template <class T1,class T2>
//class someclass
//{…};
//someclass<int,double> obj;


//21  a rult of thumb

/*If your class needs any of

a copy constructor,
an assignment operator,
or a destructor,

 defined explictly, then it is likely to need all three of them.
*/




/* 操作符重载
函数类型 operator 运算符名称 (形参表列)
{
    对运算符的重载处理
 }

只可以重载c++已有的操作符，**就不可以重载，重载不改变操作数，优先级，结核性，不可以有默认的参数，重载函数可以是友元函数。
 重载函数申明为友元的动机是：普通的成员函数在调用操作符时会有this指针一并传入，这就要求操作符的做操作数，即发起这个操作的变量是该this指针的类对象，如果想让其他对象也能发起该操作，那就要用友元，因为友元函数的输入同时需要左右操作数，而没有默认的this指针。但是仍然不能满足交换率
 
 << >> 就只能用友元函数来重载，因为左操作数必须是ostream类的对象，比如cout，另一方面当有连续输出时也能接的上
 friend ostream& operator << (ostream&,Complex&);  //运算符“<<”重载为友元函数
 
 ostream& operator << (ostream& output,Complex& c) //定义运算符“<<”重载函数
 {
    output<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
    return output;
 }
 
 friend istream& operator >> (istream&,Complex&); //声明重载运算符“>>”

 istream& operator >> (istream& input,Complex& c)  //定义重载运算符“>>”
 {
 cout<<"input real part and imaginary part of complex number:";
 input>>c.real>>c.imag;
 return input;
 }

 不能重载的运算符只有5个：
 .  (成员访问运算符)
 .*  (成员指针访问运算符)
 ::  (域运算符)
 sizeof  (长度运算符)
 ?:  (条件运算符）
 
 Time operator++( );//声明前置自增运算符“++”重载函数
 Time operator++(int);//声明后置自增运算符“++”重载函数

*/


/* 转换构造函数，只有一个参数的构造函数，如果加了explicit，那么就会要求输入一定要匹配某单参数构造函数的输入要求
 Complex(double r) {real=r;imag=0;}

 */

/* 类型转换函数，将某个类转换成其他类型
 在函数名前面不能指定函数类型，函数没有参数。其返回值的类型是由函数名中指定的类型名来确定的。类型转换函数只能作为成员函数，因为转换的主体是本类的对象。不能作为友元函数或普通函数。
 当需要的时候，编译系统会自动调用这些函数，建立一个无名的临时对象(或临时变量)。当执行double + complex时, complex会被系统转换为double
 operator double( ) {return real;}

 配合重载为友元函数的操作符重载函数，可以满足交换律
 
 
 */



/* 继承与派生
 
 1 在声明派生类时，一般还应当自己定义派生类的构造函数和析构函数，因为构造函数和析构函数是不能从基类继承的。同时，初始化派生类的时候还必须初始化基类
 2 公用的，派生类内和派生类外都可以访问。
 受保护的，派生类内可以访问（指的是派生类对象的成员函数可以），派生类外不能访问(即便用派生类对象.xxx,也不行)，其下一层的派生类可以访问。
 私有的，派生类内可以访问，派生类外不能访问。
 举例：a有保护成员i,b 共有继承自A, c 保护继承自B，那么C可以用成员i,但是c外面看不到i
 3 必须放在初始化列表里：
 1.常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
 2.引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
 3. 没有默认构造函数的类类型（包括基类，类成员，他们都需要初始化）。派生类会自动调用他们的默认构造函数，但是如果构造函数有参数，那么需要手动调用，并且要放在列表里，不可放在函数体里
 
 执行派生类构造函数的顺序是：
 调用基类构造函数，对基类数据成员初始化；
 调用类成员构造函数，对子对象数据成员初始化；
 再执行派生类构造函数本身，对派生类数据成员初始化。
 多继承时，调用基类构造函数的顺序是按照声明派生类时基类出现的顺序。
 
 在派生类构造函数里，不要列出每一层派生类的构造函数，只需写出其上一层派生类（即它的直接基类）的构造函数即可
 
 
 虚基类：针对菱形继承
 C++提供虚基类(virtual base class)的方法，使得在继承间接共同基类时只保留一份成员。虚基类并不是在声明基类时声明的，而是在声明派生类时，指定继承方式时声明的。因为一个基类可以在生成一个派生类时作为虚基类，而在生成另一个派生类时不作为虚基类。
 class B: virtual public A  直到最外围的派生，要一路virtual下去
 在最后的派生类中不仅要负责对其直接基类进行初始化，还要负责对虚基类初始化。这和普通派生类只要管上一层基类不同。

 
 派生类与基类的相互赋值：
 1 派生类对象可以赋值给基类对象
 2 派生类对象可以初始化基类对象的引用。此时基类的引用与派生类中的基类部分共享同一段存储单元，与派生类对象中的基类部分有相同的起始地址。
 3 指针也是类似，通过指向基类对象的指针，只能访问派生类中的基类成员，而不能访问派生类增加的成员 （除非是虚函数）。
 
 */



/*  多态
 
 1 静态多态：函数的重载、运算符重载都是多态现象
   动态多态： 虚函数
 2 派生类对象如果想访问被覆盖掉的基类函数，需要加上基类的作用域，base class :: ,或者用指针
 3 在派生类中重新定义虚函数，要求参数表与基类的虚函数相同，多态和重载最大的区别就是，多态必须一致，重载必须不一致。至于覆盖，只要派生类有和基类名字一样的函数就覆盖，是另一种实现多态的方法，如果此时派生类要调用基类的函数必须加上类名。
 4 为什么析构函数要是虚的：如果派生类对象是动态开辟的，那么如果析构函数不是虚的，delete那个基类指针的时候只会触发基类的析构函数，并不会触发派生类的析构函数。在派生类的虚析构函数被调用的时候，父类的虚析构函数会随机被调用。
 如果将基类的析构函数声明为虚函数时，由该基类所派生的所有派生类的析构函数也都自动成为虚函数，即使派生类的析构函数与基类的析构函数名字不相同。
 4.5 返回值不一样的虚函数：如果虚函数的基类实例返回类类型的引用或指针，那么该虚函数的派生类实例可以返回基类实例返回的类型的派生类（或指针|引用）
 Item_base::
 virtual Item_base* clone() const {return new Item_base(*this);}

 Bulk_item::
 Bulk_item* clone() const {return new Bulk_item(*this);}
 
 5 纯虚函数：纯虚函数（定义一个虚函数，然后=0）的作用是在基类中为其派生类保留一个函数的名字，以便派生类根据需要对它进行定义。如果在一个类中声明了纯虚函数，而在其派生类中没有对该函数定义，则该虚函数在派生类中仍然为纯虚函数。
 6 抽象类：凡是包含纯虚函数的类都是抽象类。因为纯虚函数是不能被调用的，包含纯虚函数的类是无法建立对象的。虽然抽象类不能定义对象(或者说抽象类不能实例化)，但是可以定义指向抽象类数据的指针变量。

 */





/* 输入输出流

 1 c的printf scanf是不安全的，在C++的输入输出中，编译系统对数据类型进行严格的检查，凡是类型不正确的数据都不可能通过编译。因此C++的I/O操作是类型安全(type safe)的
 2 在C++中，输入输出流被定义为类。C++的I/O库中的类称为流类(stream class)。 用流类定义的对象称为流对象。流是与内存缓冲区相对应的，或者说，缓冲区中的数据就是流。
 3 ios派生出istream, ostream, 再一起派生出iostream, 再派生出fstream针对文件I/O
 4 iostream里面有4种流对象：cin cout cerr clog, cout若以标准输出设备为参数就打印到屏幕上 ostream cout(stdout) ， << >> 不再表示移位，而是进行了重载，表示流插入运算符，把指定的内容查到输入/输出流当中
 5 cout流就是流向显示器的数据，cout流是容纳数据的载体，它并不是一个运算符。cout流在内存中对应开辟了一个缓冲区，用来存放流中的数据，当向cout流插 人一个endl时，不论缓冲区是否已满，都立即输出流中所有数据，然后插入一个换行符， 并刷新流（清空缓冲区）。注意如果插人一个换行符”\n“（如cout<<a<<"\n"），则只输出和换行，而不刷新cout流(但并不是所有编译系统都体现出这一区别）。
 6 cerr流对象是标准错误流，cerr流已被指定仅与显示器关联。cerr<<"a is equal to zero,error!"<<endl; cerr是不经过缓冲区，直接向显示器上输出有关信息，而clog中的信息存放在缓冲区中，缓冲区满后或遇endl时向显示器输出
 7 格式化输出要用#include <iomanip>
   cout<<setw(10)<<pt<<endl;
   如果不用的话，用cout自带的成员函数
   cout.width(14);
   cout<<pi<<endl;
   cout.unsetf(ios::scientific);  停止上一种模式才能开始下一种
   cout.put('\n') 专门用来输出一个字符, C中putchar

 8 cin 只有在输入完数据再按回车键后，该行数据才被送入键盘缓冲区，形成输入流，提取运算符“>>”才能从中提取数据, 从流中提取数据时通常跳过输入流中的空格、tab键、换行符等空白字符. 所以在有多个cin的时候需要一起输入，而不是一个个输入。 如果提取失败，cin==0. 结束按ctrl+Z/D
     cin.get()输入一个字符，无论什么，直到EOF，用-1表示
     (c=cin.get())!=EOF
      
    // getline  vs get, 读完指针是否后移的区别
    cin.getline() 用getline函数从输入流读字符时，遇到终止标志字符时结束，指针移到该终止标志字符之后，下一个getline函数将从该终止标志的下一个字符开始接着读入，如本程序运行结果所示那样。如果用cin.get函数从输入流读字符时，遇终止标志字符时停止读取，指针不向后移动，仍然停留在原位置。下一次读取时仍从该终止标志字符开始
     // getline vs cin<<  ,是否能读空白的区别
     用“cin<<”读数据时以空白字符(包括空格、tab键、回车键)作为终止标志，而用cin.getline()读数据时连续读取一系列字符，可以包括空格。用“cin <<”可以读取C++的标准类型的各类型数据（如果经过重载，还可以用于输入自定义类型的数据），而用cin.getline()只用于输入字符型数据。
 9 根据文件中数据的组织形式，可分为ASCII文件和二进制文件，二进制文件又称内部格式文件或字节文件，是把内存中的数据按其在内存中的存储形式原样输出到磁盘上存放。如果在程序运行过程中有些中间结果数据暂时保存在磁盘文件中，以后又需要输入到内存的，这时用二进制文件保存是最合适的。如果是为了能显示和打印以供阅读，则应按ASCII码形式输出。高级IO是指2进制格式转换到ascii形式，内存到显示器，低级IO是不带转换的，效率更高
 
 10 文件流是以外存文件为输入输出对象的数据流，若要对磁盘文件输入输出，就必须通过文件流来实现，通过文件流对象将数据从内存输出到磁盘文件，或者通过文件流对象从磁盘文件将数据输入到内存,和标准输出的cin cout不同，文件流需要自己定义并且指定哪个磁盘作为输出。读写之前先要绑定一个文件，见代码
 
 11 ascii文件流：可以通过文件流对象和流插入运算符“<<”及流提取运算符“>>”实现对磁盘 文件的读写，如同用cin、cout和<<、>>对标准设备进行读写一样。put、get、getline 也可以用
    ofstream outfile("f1.dat",ios::out);
    outfile<<a[i]<<" "; 在向磁盘文件输出一个数据后，要输出一个(或几个)空格或换行符，以作为数据间的分隔，否则以后从磁盘文件读数据时，10个整数的数字连成一片无法区分。
    ifstream infile("f1.dat",ios::in|ios::nocreate);
    infile>>a[i];
 
 12 二进制文件流：主要用的是指针，打开文件时要用ios::binary
 ofstream outfile("stud.dat",ios::binary)
 outfile.write(字符指针(char *),多少字节);
 outfile.close( );
 ifstream infile("stud.dat",ios::binary);
 infile.read((char*)&stud[0],sizeof(stud));
  
 
 13 字符串流：以内存中用户定义的字符数组(字符串)为输入输出的对象，即将数据输出到内存中的字符数组，或者从字符数组(字符串)将数据读入。字符串流也称为内存流。
 */


/* 命名空间
 1 定义命名空间的时候不可以放在函数,类,其他命名空间内部,只能放在全局作用域 (::),或者该命名域内部定义。namespace name{}不能加分号
 2 特性1： 命名空间中定义的名字可以被命名空间中的其他成员直接访问, 不需要加：：，
          并且如果函数名是加了：：声明的，那那些形参可以直接调用那个作用域里的成员。
          cpp::A cpp::operator+(const A&), 形参不需要cpp::A
          或者实参是某个类的实体或者指针/引用，那么在搜索函数时会一并搜索实参所在类的命名空间。getline(std::cin,string s), getline 会在std和string的命名空间里寻找。 A:: obj, f(obj) f还包括了定义A及其基类的命名空间中的函数。
 3 特性2： 命名空间可以不连续，实现接口和实现的分离 (文件间也可以分离),分离声明和定义。
   .h 文件里：
   namespace cpp{class A;}
   .cpp 文件里
   #include<cpp.h>
   namespace cpp{ A defination}
   .main 里面可以用别名
   namespace alisas = cpp
   alisas::A a
 
 4 当嵌套定义命名空间的时候，内部的函数会屏蔽外面的，外围要调用内层的必须 wai::nei::func
 5 特性3： 无名命名空间 namespace{}, 仅有效于当前的文件（类似于且优于static），作用域同于一个全局变量。如果头文件中定义了无名空间，那么每个文件会产生自己独立的局部实体。不需要::即可调用，

 7 using 声明每次可以注入一个特定的函数，作用域相当于using的作用域。using std::map
   using 指示，命名空间内所有函数均被可见，作用域是整个using指示所在的上一层空间(注意和指示所在域之外的全局空间命名存在二义性冲突)。不应在头文件中使用，这样的话每个引用头文件的都会被迫注入该namespace里全部的函数。
 8 对于命名空间中的类，查找的顺序：成员，基类，外围作用域（需提前声明）。域名调用的顺序是查找的逆序，A::c1::f3() f3->c1->A



*/

template<typename T>  //模板声明，其中T为类型参数
T max(T a,T b,T c) //定义一个通用函数，用T作虚拟的类型名
{
    //namespace hehe{
    if(b>a) a=b;
    if(c>a) a=c;
    return a;//}
}

//i=max(i1,i2,i3); //调用模板函数，此时T被int取代

// 声明
struct Student//声明一个结构体类型Student
{
    int num;  //包括一个整型变量num
    char name[20];  //包括一个字符数组name，可以容纳20个字符
    char sex;  //包括一个字符变量sex
    int age;   //包括一个整型变量age
    float score;   //包括一个单精度型变量
    char addr[30];  //包括一个字符数组addr，可以容纳30个字符
}student1={10001, "Zhang Xin", 'M', 19, 90.5, "Shanghai"}, studn[10];  //最后有一个分号,结构体数组


Student  student2{ 10002, "Wang Li", 'F', 20, 98, "Beijing"}; // 定义





#include <iostream> //预处理
#include <iomanip> //控制输出的样式
//#include "STL.cpp"
using namespace std; // 用标准库



class Time
{
public:
    Time(){cout<<"base"<<endl;}; // 构造函数加explicit就是不让该构造函数被隐士的用作转换函数，从而作为其他函数的输入
    Time(int,int,int);
    Time(int); // 如果有explicit,就表明不允许隐式的把int转换为time，除非显示的构造
    int hour;
    int minute;
    int sec;
    void get_time( );
};

Time::Time(int a):hour(a){

}


Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    sec=s;
}
void Time::get_time( ) //声明公有成员函数
//定义公有成员函数
{
    cout<<hour<<":"<<minute<<":" <<sec<<endl;
}


class day: public Time{

public:
    day(){cout<<"derived"<<endl;} // 自动先调用base class的默认构造函数
    ~day(){}
    void get_time(int a){cout<<a<<endl;};
};




int min(int a=2, int b=0){
    cout<<a<<endl;
    return b;
}

// 函数是由()调用，所以即便没有形参，()不可以少
int wanwan(int argc, const char * argv[]) {

    int ast = 1;
    cout<<to_string(ast)+".csv"<<endl;

    int as[3]={0,0,0};
    cout<<as<<endl;  // 数组名在表达式里的作用就是数组的起始地址
    cout<<&as[0]<<endl;

    day td; // base class如果有默认构造函数会自动调用
    td.Time::get_time(); // 派生类可直接调用基类函数, time::可以不加

    char zhuan = 'a';
    Time t = zhuan; // 调用了time(int)的转换构造函数，如果该函数是explicit，那么就要求输入是强制的int，不可以是转到的int

    Time t1(10,13,56);
    void (Time::*p3)( )=&Time::get_time;; //指向类成员函数的指针
    (t1.*p3)( ); // * 不可以少

    typedef int (*fun)(int,int);
    fun funct = & min; // 这个取地址符号，可有可无，但是加上最好，因为成员函数时必须有
    (*funct)(2,3); // 可有可无的*号
    funct(2,3); // 因为funct是指向函数的指针，所以直接调用编译器做了优化，就像字符串数组在输出的时候可以直接cout数组名

    // const int *bv = new const int[9]; //这样不可以
    cout<<sizeof(Student)<<endl; // 68个字节



// 初始化长整形，短整型
    long int a; // 4个字节有符号32767，8个字节有符号21亿，无符号42亿
    short int b;
    a=b=4; // 可以一连串的赋值，但不可以一连串的初始化

    cout<<5/3<<"\n"<<-5/3<<"\n"<<endl; // xocde用的是向零取整
    cout<<((a=3*5)=4*3)<<endl; //print 12
    int x;
    x=(a=3, 6*3); //x=3
    x=a=3, 6*a;   //x=18,逗号表达式的优先级最低

    cout<<getchar()<<endl; //输入A,输出65
    char c;
    cout<<(c=getchar())<<endl; //输入A,输出A

    double aa=123.456,bb=3.14159,cc=-3214.67;
    // 实现小数点对齐，精度对齐
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2);
    cout<<setw(10)<<aa<<endl;
    cout<<setw(10)<<bb<<endl;
    cout<<setw(10)<<cc<<endl;

    int i1=185,i2=-76,i3=567,i;
    i=max(i1,i2,i3); //调用模板函数，此时T被int取代

    if(aa==123.456){
        double b2=aa*2; //复合语句内定义的变量生命域只在复合语句内
        cout<<b2<<endl;
    }
    // cout<<b2<<endl;


    char st[]="string";
    //st="string2";  数组不可以整体赋值，因为数组名是常量

    char str1[30]="People′s Republic of";
    char str2[]="China";
    cout<<strcat(str1,str2)<<endl; //str改变


    int b3[][2]={1,2,3,4};
    int (*w)[2]= &b3[0]; // w=b3, +1是下一行
    int *p= b3[0];  // p是个一维数组的指针
    cout<<*(p+1)<<endl; // 2, 一维数组中下一个元素
    cout<<**(b3+1)<<endl; // 3
    cout<<"b3[0]"<<b3[0]<<endl;
    cout<<"b3"<<b3<<endl;




    char **o;  //定义指向字符指针数据的指针变量p
    char *name[]={"BASIC","FORTRAN","C++","Pascal","COBOL"}; // 指针数组，每个元素是一个指针
    o=name;
    cout<<*o<<endl;  //输出name[2]指向的字符串
    cout<<**o<<endl;






    // 打开一个文件流
    //ofstream outfile;  //定义ofstream类(输出文件流类)对象outfile
    //outfile.open("f1.dat",ios::out);  //使文件流与f1.dat文件建立关联，ios::binary说明2进制文件
    // ios::out l ios::noreplace  //打开一个新文件作为输出文件，如果文件已存在则返回打开失败的信息
    // ios: :trunc, 打开一个文件，如果文件已存在，则删除其中全部数据，如文件不存在，则建立新文件
    //if( !outfile.open("f1.bat", ios::app) ) 打开失败
    //outfile.close( );  //将输出文件流所关联的磁盘文件关闭

    return 0; //如果程序不能正常执行，则会自动向操作系统返回一个非零值，一般为-1




}


/*  操作系统
 
 1 systerm structure: user mode -> kernel mode -> hardware,现代操作系统 10m行
 
 2 concurrency:并发 parallel:并行。并发通常是时分的
    multiprogramming: more then one thread at a  time (one CPU )

 3 进程execution: 从program counter里面拿计算指令，解释，执行，把结果输送到寄存器，读下一条pc指令
    进程切换，要存放pc,register,然后再调用的时候返回
 
 4 hyperthreading:simultaneous multithreading,一个核跑两个线程
 5 保护线程，memory mapping： 1 memory 2 IO设备 3 CPU,use timer to switch
 
    每个program的address space 里有，从底到顶： text(代码部分),data(静态数据), heap（堆，new),stack(函数迭代放的地方)。这些是virtual的，然后通过一个映射函数（每个cpu有自己的映射函数）每个code ,data, heap ,stack到不同的物理内存，这样就能保证不同的thread之间不互相干扰
 
 6 进程的定义： a single, sequential stream of exection in its own address space.
   包含了sequential program exectuion stream + protected resources, 由PCB保存,然后context switch.
 
 process state: new, ready, running（CPU）, waiting, terminated
 
 multi-process: 需要新的address space，要拷贝父进程的一切，内存，IO，所以很贵。但是一个进程里面所有的threads共享一个address space(no protection). 但是每个thread要一个自己的TCB(stack,因为thread可以call自己,register)
 
 7 进程的两大核心问题：1 线程并发(time) 2 address spaces 保护 (space)
    并发可以用cpu的时分复用，protection可以用虚拟内存到内存的不同Mapping

 */


















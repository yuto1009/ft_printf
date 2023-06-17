// #include <stdarg.h>
// #include <stdio.h>

// int sum(int count, ...){

//     // va_list型の変数を宣言
//     va_list list;

//     // 可変長引数の取得を開始
//     va_start(list, count);

//     // 可変長引数を1個ずつ取得し、合計を求める
//     int total = 0;
//     for (int i=0; i<count; i++) 
//         total+=va_arg(list, int);

//     // 可変長変数の取得を終了
//     va_end(list);

//     //　合計を返す
//     return total;
// }

// int main(void){
//     printf();
//     return 0;
// }
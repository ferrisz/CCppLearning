#include <stdio.h>
#define NUM_OF_CLASSROOM 20    //设定课室数组上限
int main(){
  //初始化课室数量，内容为每个课室的人数，amountClass表示课室的数量
  int numOfStudent[NUM_OF_CLASSROOM] = { 0 }, amountClass = 0;  
 
  //记录学生姓名指针的二维数组，
  //首位为课室号，次位为学生学号（由0开始计），末位表示最长为8个字符。
  //调用例：&name[2][3]可得到班别为2，学号为3的同学的姓名 
  char name[NUM_OF_CLASSROOM][9][9];    
 
  int V[NUM_OF_CLASSROOM][9];    //记录每个学生所拥有泥塑的体积
  int i, j;
  int x, y, z;  //长x宽y高z，用以计算体积
  int max, min; //某课室中拥有泥塑体积最大max及最小min的学号
 
  //输入数据 
  scanf("%d", &numOfStudent[0]);
  while (numOfStudent[amountClass] != -1){
    for (i = 0; i < numOfStudent[amountClass]; i++){
      scanf("%d %d %d %s", &x, &y, &z, &name[amountClass][i]);
      //算出该班所有学生所拥有的泥塑体积
      V[amountClass][i] = x * y * z;    
    }
    scanf("%d", &numOfStudent[++amountClass]);
  }
 
  //找出每间课室拥有泥塑体积最大和最小的学生，并输出
  for (i = 0; i < amountClass; i++){
    min = max = 0;
    for (j = 0; j < numOfStudent[i]; j++){
      if (V[i][max] < V[i][j])
      max = j;
      if (V[i][min] > V[i][j])
      min = j;
    }
    printf("%s took clay from %s.", &name[i][max], &name[i][min]);
    if (i != amountClass - 1)
      printf("\n");
  }
 
  return 0;
}
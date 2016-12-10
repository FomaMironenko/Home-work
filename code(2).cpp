#include <iostream>

using namespace std;

int main()
{
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;
    for(a1=0; a1<10; a1++){
        for(a2=0; a2<10; a2++){
            for(a3=0; a3<10; a3++){
                for(a4=0; a4<10; a4++){
                    for(a5=0; a5<10; a5++){
                        for(a6=0; a6<10; a6++){
                            for(a7=0; a7<10; a7++){
                                for(a8=0; a8<10; a8++){
                                    for(a9=0; a9<10; a9++){
                                        for(a10=0; a10<10; a10++){
                                            for(a11=0; a11<10; a11++){
                                                for(a12=0; a12<10; a12++){
                                                    if((a1+a2+a3)%2==0&&(a10+a11+a12)%3==0&&(a3+a6+a9+a12)%11==0&&((a2+a4+a6+a8+a10+a12)==21)){
                                                        cout<<a1<<a2<<a3<<a4<<a5<<a6<<a7<<a8<<a9<<a10<<a11<<a12<<endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

#define citire(a,a1,a2,u){\
fgets(a,20,stdin); a1=0; a2=0;\
int i, ok=0;\
for(i=0; i<20; i++)\
{\
    if((a[i]>='0' && a[i]<='9') || a[i]== '+' || a[i]== '-' || a[i]== '*' ||a[i]== '/' ||a[i]== '%')\
    {\
        if((i>0 && (a[i-1]>='0' && a[i-1]<='9'))&& (a[i]== '+' || a[i]== '-' || a[i]== '*' ||a[i]== '/' ||a[i]== '%'))\
        {\
            ok=1;\
            u=i;\
        }\
        if(a[i]>='0' && a[i]<='9')\
        {\
            if(ok==0)a1=a1*10+(a[i]-'0');\
            else a2=a2*10+(a[i]-'0');\
        }\
    }\
}\
if(a[0]=='-')a1*=-1;\
if(a[u+1]=='-')a2*=-1;\
}
#define operatie(a,a1,a2){\
switch(a)\
{\
    case '+': printf("%d",a1+a2);\
    break;\
    case '-': printf("%d",a1-a2);\
    break;\
    case '*': printf("%d",a1*a2);\
    break;\
    case '/': \
        {\
            if(a2)printf("%.2f",(float)(a1)/(a2));\
                else printf("Numitorul nu poate fi nul!");\
        }\
    break;\
    case '%': \
        {\
            if(a2)printf("%.2f",(float)((a1)%(a2)));\
                else printf("Numitorul nu poate fi nul!");\
        }\
    break;\
}\
}


int main(){
    char cmd[10];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0){
            break;
        } else if(strcmp(cmd,"PUSH")==0) {
            int v; scanf("%d",&v);
            push(v);
        } else if(strcmp(cmd,"POP")==0) {
            if(stackEmpty()){
                printf("NULL\n");
            } else {
                int v = pop();
                printf("%d\n",v);
            }
        }
    }
    Empty();
    return 0;
}
/*
If we sum the cubes of digits of a number and
still get the same number then it is armstrong
*/

int isArmstrong(int n)
{
    int sum=0;
    int originaln=n;

    while(n>0)
    {
        int lastdigit= n%10;
        sum+= pow(lastdigit,3);
        n=n/10;
    }

    if(sum==originaln){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"not armstrong"<<endl;
    }
}

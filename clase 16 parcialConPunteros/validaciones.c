int valid_esSoloLetras(char* string)
{
   int i=0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int valid_esCuit(float cuit)
{
    if(cuit < 0 || cuit > 30999999999)
        return 0;
    else
        return 1;
}
int valid_esNum(int entero)
{
    if(entero< -999999 || entero > 999999)
        return 0;
    else
        return 1;
}

/*
Curso: SUP TEC EM ANÁLISE E DESENVOLVIMENTO E SISTEMAS
DISCLIPINA: PIM-IV
UNIP- UNIVERSIDADE PAULISTA

Autor: ANSELMO DA SILVA ROSA ANDRADE;
       RAFAEL GIANDOSO SILVA
*/

/* Bibliotecas do programa*//*===============================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <Locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
/*fim das Bibliotecas*//*====================================================================*/
 /* Bloco de registros e variaveis globais*/ /*=======================================*/
typedef struct
        {
         char nome [40];
         char email [40];
         char tel [12];
         char tel2 [12];
         char rua[20];
         char numC[10];
         char bairro[20];
         char estado[20];
         char complemento[40];
         char cep [9];
         char cidade[20];
         char comorb[40];
         char cpf [12];
         char dia[3];
         char mes[3];
         char ano[5];
         int idade;
         char diaC[3];
         char mesC[3];
         char anoC[5];
         int anoPaciente;
        }Paciente;

        /* a1 é uma struct do tipo paciente*/
        Paciente a1;

        char  decisao;
        char op;
        int menu;
        int i;
        char traco[]= "+---------------------------------------------------------------+";





 /*FIM Bloco de registros e variaveis globais*/ /*=======================================*/



int cadastro()
{

        voltacadastro:
        for (i=0;i<1;i++)
        {

        char cpfTemp[12];


            FILE *arqRisco; /*ponteiro para o arquivo*/
            arqRisco = fopen ("risco.txt", "a+");

            FILE *arqCad; /*ponteiro para o arquivo*/
            arqCad = fopen ("cadastro.dat", "a+b");

            FILE *ptrCPF;
            ptrCPF = fopen ("cpf.dat","a+b");

            /*inicio cadastreo cpf*/ /*============================================*/

            voltaCPF:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        CADASTRO DO CPF       ****************        \n");
            printf("\t                                                                            \n");

            printf("\tDigite o CPF:");
            fflush(stdin);
            gets(a1.cpf);

            printf("---------------------------------------------------");
                if(strlen(a1.cpf) == 0)
                    {
                    printf("\tPreencha O Campo do CPF!!");printf("\n");
                    system("pause");
                    goto voltaCPF;
                    break;
                    }
                for(i=0; i<a1.cpf[i]; i++)
                    {
                    if(!(a1.cpf[i]>='0' && a1.cpf[i]<='9' && strlen(a1.cpf)==11))
                        {
                        printf("\n\t***Inválido. \n\tVerifique se digitou apenas numeros \n\t e se não excedeu ou não atingiu a quantidade permitida***\n");
                        system("pause");
                        goto voltaCPF;
                        }
                    }


        FILE *consulta;
        consulta = fopen("cpf.dat","rb");
        while((fscanf(consulta,"%s",&cpfTemp)) !=EOF)
            {
                if (strcmp(a1.cpf,cpfTemp ) == 0)
                {
                    printf("\n\n***Já consta no sistema um cadastro com esse número de cpf***\n");
                    system("pause");
                    goto voltaCPF;
                }
            }
            /*fim cadastro cpf*/ /*======================================*/


            /*inicio do cadastro nome*/ /*=========================================*/
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      **************    CADASTRO DO NOME DO PACIENTE     ******************       \n");
            printf("\t                                                                            \n");


            voltaNome:
            printf("\tDigite o NOME:");
            fflush(stdin);
            gets(a1.nome);
            printf("---------------------------------------------------");

             if(strlen(a1.nome)==0)
                {
                goto voltaNome;
                }

            //Inicio For
            for(i=0; i<a1.nome[i];i++)
                {
                if (a1.nome[i] == ' ')
                    {
                    a1.nome[i] = '°';
                    }
                        if(a1.nome[i] >= 'a' && a1.nome[i] <= 'z' || a1.nome[i] >= 'A' && a1.nome[i] <= 'Z' || a1.nome[i] == '°')
                        {
                        if(a1.nome[i] == '°')
                            {
                            a1.nome[i] = ' ';
                            }
                        }
                }

            /*fim cadastro nome*/ /*===============================================*/



            voltaTelefone1:

            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ****************     CADASTRO DO TELEFONE    ******************       \n");
            printf("\t                                                                            \n");


            printf("\tDigite os números todos juntos XXXX...\n\n");
            printf("\tINFORME O N° DE TELEFONE PRINCIPAL: ");
            fflush(stdin);
            gets(a1.tel);printf("\n");
            printf("---------------------------------------------------");

            if(strlen(a1.tel) == 0)
            {
            goto voltaTelefone1;
            }

            for(i=0; i<a1.tel[i]; i++)
                {
                if(!(a1.tel[i]>='0' && a1.tel[i]<='9'))
                    {
                    printf("\n***Inválido. \nVerifique se digitou apenas numeros\n***");
                    goto voltaTelefone1;
                    break;
                    }
                }

            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ****************     CADASTRO DO TELEFONE    ******************       \n");
            printf("\t                                                                            \n");

            voltaTelefone2:
            printf("\n\n\tINFORME O N° DE TELEFONE 2: ");
            printf("\n\tCaso não houver, deixe em branco");
            printf("\ntDigite os números todos juntos XXXX...\n\n");
            fflush(stdin);
            gets(a1.tel2);
            printf("---------------------------------------------------");

            for(i=0; i<a1.tel2[i]; i++)
                {
                if(!(a1.tel2[i]>='0' && a1.tel2[i]<='9' || a1.tel2[i]=='0'))
                    {
                    printf("\n***Inválido. \nVerifique se digitou apenas numeros\n***");
                    goto voltaTelefone2;
                    break;
                    }
                }
        /*cadastro da Data de nascimento do pasciente*/ /*===================================*/
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        DATA DE NASCIMENTO       ****************       \n");
            printf("\t                                                                            \n");

        printf("\n\t°DATA DE NASCIMENTO");
            rDianascimento:
            printf("\n\t    =>DIA dd : ");
            fflush(stdin);
            gets(a1.dia);


             if(strlen(a1.dia) == 0){
                goto rDianascimento;
            }



            for(i=0; i<a1.dia[i]; i++)
                {
                    if(!(a1.dia[i]>='0' && a1.dia[i]<='9' && strlen(a1.dia)==2))
                    {
                        printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida***\n");
                        goto rDianascimento;
                    }
                }

            rMesNascimento:
            printf("\t          =>MÊS mm : ");
            fflush(stdin);
            gets(a1.mes);

            if(strlen(a1.mes) == 0)
                {
                goto rMesNascimento;
                }

            for(i=0; i<a1.mes[i]; i++)
                {
                    if(!(a1.mes[i]>='0' && a1.mes[i]<='9' && strlen(a1.mes)==2))
                    {
                        printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                        goto rMesNascimento;
                        break;
                    }

                }
            voltaAnoNascimento:
            printf("\t             =>ANO aaaa : ");
            fflush(stdin);
            gets(a1.ano);

            if(strlen(a1.ano) == 0)
                {
                goto voltaAnoNascimento;
                }

            printf("---------------------------------------------------");
            for(i=0; i<a1.ano[i]; i++)
                {
                    if(!(a1.ano[i]>='0' && a1.ano[i]<='9' && strlen(a1.ano)==4))
                    {
                    printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                    goto voltaAnoNascimento;
                    }
                }


        /*fim do cadastro Data de nascimento*/ /*===================================*/


           /*inicio cadastro endereço*//*=================================*/

            rRua:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\tRUA: ");
            fflush(stdin);
            gets(a1.rua);

            if(strlen(a1.rua) == 0)
                {
                goto rRua;
                }

            printf("---------------------------------------------------");


            rNumero:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\tNÚMERO: ");
            gets(a1.numC);

            if(strlen(a1.numC) == 0)
                {
                goto rNumero;
                }

            for(i=0; i<a1.numC[i]; i++)
                {
                if(!(a1.numC[i]>='0' && a1.numC[i]<='9'&& strlen(a1.numC)<11))
                    {
                        printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                        goto rNumero;
                    }

                }

            printf("---------------------------------------------------");

            rComplemento:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\tOpcional. ");
            printf("\n\tCOMPLEMENTO: ");
            gets(a1.complemento);



            printf("---------------------------------------------------");

            rBairro:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");


            printf("\n\tBAIRRO: ");
            fflush(stdin);
            gets(a1.bairro);

            if(strlen(a1.bairro) == 0)
                {
                goto rBairro;
                }
            printf("---------------------------------------------------");

            rCidade:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");


            printf("\n\tCIDADE: ");
            fflush(stdin);
            gets(a1.cidade);

            if(strlen(a1.cidade) == 0)
                {
                goto rCidade;
                }

            for(i=0; i<a1.cidade[i];i++)
                {
                    if (a1.cidade[i] == ' ')
                        {
                            a1.cidade[i] = '°';
                        }
                            if
                                (a1.cidade[i] >= 'a' && a1.cidade[i] <= 'z' || a1.cidade[i] >= 'A' && a1.cidade[i] <= 'Z' || a1.cidade[i] == '°')
                                {
                                    if(a1.cidade[i] == '°')
                                    {
                                        a1.cidade[i] = ' ';
                                    }
                                }
                                else
                                    {
                                        printf("\n***Caracter inválido. Informe apenas letras***");
                                        goto rCidade;
                                    }
                }
            printf("---------------------------------------------------");

            rEstado:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");


            printf("\n\tESTADO: ");
            fflush(stdin);
            gets(a1.estado);

            if(strlen(a1.estado) == 0)
                {
                goto rEstado;
                }
            printf("---------------------------------------------------");

            rCep:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t      ***************        ENDEREÇO DO PACIENTE       ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\tCEP: ");
            fflush(stdin);
            gets(a1.cep);

            if(strlen(a1.cep) == 0)
                {
                goto rCep;
                }

            for(i=0; i<a1.cep[i]; i++)
                {
                    if(!(a1.cep[i]>='0' && a1.cep[i]<='9'&&strlen(a1.cep)<9))
                        {
                        printf("\n******Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\nDigite os 8 números do CEP***");
                        goto rCep;
                        }
                }

            /*Fim cadastro endereço*/ /*========================================*/

            /* cadastro do email*/ /*====================================*/

            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t     ***************   ENDEREÇO DE E-MAIL DO PACIENTE   ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\tDeixe em branco caso não houver:");
            printf("\n\tEMAIL: ");
            fflush(stdin);
            gets(a1.email);

            printf("---------------------------------------------------");

            /*fim cadastro email*/ /*============================================*/



            /* Bloco para averificação se o paciente tem alguma comorbidade*//*=======*/


            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t     ***************     ===========================   ****************       \n");
            printf("\t                                                                            \n");

            fflush(stdin);
            printf(" \n\tO paciente possui alguma comorbidade? ");
            printf(" \n\t( S / N ) (S) para sim, (N) para nao.\n ");
            scanf("%s", &decisao);


            if (decisao =='s' || decisao == 'S')
                {
                    system("pause");
                    system("cls");
                    system("color 1F");
                    printf("\t                                                                            \n");
                    printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
                    printf("\t                                                                            \n");
                    printf("\t     ***************     ===========================   ****************      \n");
                    printf("\t                                                                            \n");
                    printf("\tDigite a comorbidade do paciente: ");
                    fflush(stdin);
                    gets(a1.comorb);
                    fflush(stdin);
                }
                else
                {
                    char temp[30]= "nao possui comorbidade. ";
                    sprintf(a1.comorb, "%s", temp);
                }


        /*Bloco data do diagnostico*/ /*===========================================*/


            rDiaMorb:
            system("cls");
            system("color 1F");
            printf("\t                                                                            \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------#\n");
            printf("\t                                                                            \n");
            printf("\t     ***************   DATA DO DIAGNÓSTICO DE COVID 19   ****************       \n");
            printf("\t                                                                            \n");

            printf("\n\t   =>DIA dd: ");
            fflush(stdin);
            gets(a1.diaC);

            if(strlen(a1.diaC) == 0)
                {
                goto rDiaMorb;
                }

            for(i=0; i<a1.diaC[i]; i++)
                {
                    if(!(a1.diaC[i]>='0' && a1.diaC[i]<='9' && strlen(a1.diaC)==2))
                        {
                        printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                        goto rDiaMorb;
                        }
                }
            rMesMorb:
            printf("\t        =>MÊS mm: ");
            fflush(stdin);
            gets(a1.mesC);


            if(strlen(a1.mesC) == 0)
                {
                goto rMesMorb;
                }

                for(i=0; i<a1.mesC[i]; i++)
                    {
                    if(!(a1.mesC[i]>='0' && a1.mesC[i]<='9' && strlen(a1.mesC)==2))
                        {
                            printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                            goto rMesMorb;
                        }

                    }
            rAnoMorb:
            printf("\t              =>ANO aaaa: ");
            fflush(stdin);
            gets(a1.anoC);

            if(strlen(a1.anoC) == 0)
                {
                goto rAnoMorb;
                }

            for(i=0; i<a1.anoC[i]; i++)
                {
                if(!(a1.anoC[i]>='0' && a1.anoC[i]<='9' && strlen(a1.anoC)==4))
                    {
                    printf("\n***Inválido. \nVerifique se digitou apenas numeros \n e se não excedeu ou não atingiu a quantidade permitida\n***");
                    goto rAnoMorb;
                    }
                }


            /*bloco para calcular a idade do paciente*/ /*==============================*/

            int anoDiagnostico;
            anoDiagnostico= atoi(a1.anoC);
            a1.anoPaciente = atoi(a1.ano);
            a1.idade = anoDiagnostico - a1.anoPaciente; //ano dignostico - ano idade

            if (a1.mesC<a1.mes)
              {
                a1.idade--;
              }

            /*fim bloco para calcular idade do paciente*/ /*=========================*/


            /* bloco apresentação dos daos cadastros*/ /*==================================*/

              system("cls");
              system("color 1F");
              printf("\t                                                                               \n");
              printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  ----------------------#\n");
              printf("\t                                                                               \n");
              printf("\tNOME:%s                                                                        \n",a1.nome);
              printf("\t                                      CPF:%s                                   \n",a1.cpf);
              printf("\tTELEFONE: %s                                                                   \n",a1.tel);
              printf("\t                                      IDADE:%i                                 \n",a1.idade);
              printf("\tTELEFONE: %s                                                                   \n",a1.tel2);
              printf("\t                                      NASCIMENTO: %s/%s/%s                 \n",a1.dia,a1.mes,a1.ano);
              printf("\tRUA: %s                                                                        \n",a1.rua);
              printf("\t                                      N: %s          BAIRRO: %s                \n",a1.numC,a1.bairro);
              printf("\tCIDADE: %s                                                                     \n",a1.cidade);
              printf("\t                                      ESTADO: %s     CEP: %s                   \n",a1.estado,a1.cep);
              printf("\tE-MAIL: %s                                                                     \n",a1.email);
              printf("\t                                      DATA DO DIAGNOSTICO: %s/%s/%s        \n",a1.diaC,a1.mesC,a1.anoC);
              printf("\tCOMORBIDADES: %s                                                               \n",a1.comorb);
              printf("\t                                                                               \n");
              printf("\t#-------------------------------------------------------------------------------#");
              printf("\n\n\t Deseja confirmar o cadastro? ");
              printf(" \n\t( S / N ) S para sim, N para nao: ");
              fflush(stdin);
              printf("\t");op = tolower(getchar()) ; //scanf("%s",&resp);
              fflush(stdin);

              if (op=='s')
              {

                fprintf(ptrCPF, "\n%s", a1.cpf);
                fclose(ptrCPF);


                if (a1.idade > 64)
                    {
                    fprintf(arqRisco, "\n\tIDADE: %2.i",a1.idade);
                    fprintf(arqRisco, "\n\tCEP: %s",a1.cep);
                    fprintf(arqRisco, "\n\n\%s",traco);
                    fclose(arqRisco);
                    }
                else
                    {
                    fclose(arqRisco);
                    }

                fwrite(&a1, sizeof (Paciente),1,arqCad);
                fclose(arqCad);

                printf("\n\nDADOS CADASTRADOS COM SUCESSO!\n\n");
                system("pause");
               }
               else
               {
                   goto voltacadastro;
               }

                system("cls");
                system("color 1F");
                printf("\n\n\t Dejesa fazer um novo cadastro? ");
                printf(" \n\t( S / N ) S para sim, N para nao: ");
                fflush(stdin);
                printf("\t");op = tolower(getchar()) ; //scanf("%s",&resp);
                if (op == 's')
                {

                goto voltacadastro;

                }

            }
return 0;
}

int consulta()
{

    FILE *arqCad; /*ponteiro para o arquivo*/
    arqCad =fopen("cadastro.dat","rb");
        if( arqCad == NULL)
            {
            printf("ainda não possui cadastro salvos!");
            system("pause");
            }

    while (fread (&a1, sizeof(Paciente),1,arqCad)!= 0)
       if(a1.cpf> 0)
         {
          { system("cls");
            system("color 1F");
            printf("\t                                                                                  \n");
            printf("\t#-------------------  CADASTRO DE PACIENTES (COVID 19)  -------------------------#\n");
            printf("\t                                                                                  \n");
            printf("\tNOME:%s                                                                           \n",a1.nome);
            printf("\t                                            CPF:%s                                \n",a1.cpf);
            printf("\tTELEFONE: %s                                                                      \n",a1.tel);
            printf("\t                                     IDADE: %i                                    \n",a1.idade);
            printf("\tTELEFONE: %s                                                                      \n",a1.tel2);
            printf("\t                                     NASCIMENTO: %s / %s / %s                     \n",a1.dia,a1.mes,a1.ano);
            printf("\tRUA: %s                                                                           \n",a1.rua);
            printf("\t                                     N: %s         BAIRRO: %s                     \n",a1.numC,a1.bairro);
            printf("\tCIDADE: %s                                                                        \n",a1.cidade);
            printf("\t                                     ESTADO: %s    CEP: %s                        \n",a1.estado,a1.cep);
            printf("\tE-MAIL: %s                                                                        \n",a1.email);
            printf("\t                                     DATA DO DIAGNOSTICO: %s / %s/ %s             \n",a1.diaC,a1.mesC,a1.anoC);
            printf("\tCOMORBIDADES: %s                                                                  \n",a1.comorb);
            printf("\t                                                                                  \n");
            printf("\t#-------------------------------------------------------------------------------#\n\n");
            system("pause");
          }
         }
         return 0;
}


int main()
    {

        setlocale(LC_ALL,"Portuguese");

        char user[20];
        char password[20];
        char userTemp[20]; //ARMAZENA O USUARIO PARA CONSULTA
        char passwordTemp[20]; //ARMAZENA A SENHA PARA CONSULTA
        int menu;

            while(1)
        {
            voltaLogin:;
            system("cls");
            system("color 1F");//DEFINE A COR  TIPO
            printf("\t                                                                                 \n");
            printf("\t+===============================================================================+\n");
            printf("\t*........PPPPPPPP.....II....MMM........MMM.....11....VV...............VV........*\n");
            printf("\t*........PP.....PP..........MM.MM.....MMMM.....11.....VV.............VV.........*\n");
            printf("\t*........PP.....PP....II....MM..MM...MM.MM.....11......VV...........VV..........*\n");
            printf("\t*........PP.....PP....II....MM...MM.MM..MM.....11.......VV.........VV...........*\n");
            printf("\t*........PPPPPPPP.....II....MM....MMM...MM.....11........VV.......VV............*\n");
            printf("\t*........PP...........II....MM.....M....MM.....11.........VV.....VV.............*\n");
            printf("\t*........PP...........II....MM..........MM.....11..........VV...VV..............*\n");
            printf("\t*........PP...........II....MM..........MM.....11............VVV................*\n");
            printf("\t*........PP...........II....MM..........MM.....11.............V.................*\n");
            printf("\t*...............................................................................*\n");
            printf("\t+===============================================================================+\n");
            printf("\t*                                                                               *\n");
            printf("\t*                  ***************************************************          *\n");
            printf("\t*                  *               [1] LOGAR NO SISTEMA              *          *\n");
            printf("\t*                  *          [2] CADASTRAR USUÁRIO E SENHA          *          *\n");
            printf("\t*                  *                       [0] SAIR                  *          *\n");
            printf("\t*                  ***************************************************         *\n");
            printf("\t*                                                                               *\n");
            printf("\t+==============================================================================+*\n");
            printf("\t*                             Introduza a opcao:                                *\n");
            fflush(stdin);

            while(!scanf("%d",&menu))
                {
                while(getchar()!='\n')
                    {
                    printf("\n");
                    printf("             Atenção ! Voce digitou uma letra, o sistema so aceita numeros !\n");
                    printf("             -------------------------------------------------------------\n");
                    }
                }

            switch(menu)
            {
                case 1:
                {
                            system("cls");
                            system("color 1F");//DEFINE A COR  TIPO
                            printf("\t  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                            printf("\n\t                      LOGIN                             ");
                            printf("\n\n\t  ---------------------------------------------------\n\n");
                            printf("\t  USUARIO: ");
                            fflush(stdin);
                            gets(user);
                            printf("\n\t  ---------------------------------------------------\n\n");
                            printf("\t  SENHA: ");
                            fflush(stdin);
                            gets(password);

                            FILE *log;
                            log =fopen("login.dat","rb");
                            while((fscanf(log,"%s %s",&userTemp, &passwordTemp)) !=EOF)
                                {
                                if ( ( strcmp( userTemp, user) == 0) && ( strcmp( passwordTemp, password ) == 0 ))
                                {
                                    Beep(1200,200);
                                    printf("\n   Logado com sucesso");
                                    menuInicial();
                                    break;
                                }
                                    system("cls");
                                    printf("\n  (Usuário e/ou senha incorreto)\n");
                                    printf("\n  (Tente novamente!)\n");
                                    Beep(565,2000);
                                    system("pause");
                                    goto voltaLogin;
                                    break;
                                }
                    }
                case 2:;
                    {

                        voltaCadastro:
                        system("cls");
                        system("color 1F");//DEFINE A COR  TIPO
                        printf("  \n\t             CADASTRO DE USUÁRIO E SENHA            ");
                        printf("\n\n\t  ---------------------------------------------------\n");
                        printf("\n\t  USUÁRIO: ");
                        fflush(stdin);
                        gets(user);

                        if(strlen(user) == 0)
                            {
                            goto voltaCadastro;
                            }

                        printf("\n\t  ---------------------------------------------------\n");
                        rPassword:
                        printf("\n\t  SENHA: ");
                        fflush(stdin);
                        gets(password);

                        if(strlen(password) == 0)
                            {
                            goto rPassword;
                            }

                        printf("\n\t  ---------------------------------------------------\n");
                        printf("\n\t  CONFIRMAR SENHA: ");
                        fflush(stdin);
                        gets(passwordTemp);

                        if (strcmp( password, passwordTemp) == 0)
                            {
                                FILE *ponteiro1;
                                ponteiro1 =fopen("login.dat","a+b");
                                fprintf(ponteiro1, "\n%s", user);
                                fprintf(ponteiro1, "\n%s", password);

                                printf("  USUÁRIO E SENHA CADASTRADO COM SUCESSO\n");
                                Beep(1200,200);
                                printf("\n  Pressione enter para retornar a tela inical...");
                                scanf("ENTER");
                                system("cls");
                                fclose(ponteiro1);
                                goto voltaLogin;
                            }
                        break;
                    }

                    case 0:
                        {
                            printf("\n\n***************SISTEMA FINALIZADO*******************\n\n");
                            exit(1);
                            break;
                        }
                    default:
                        {
                            printf("\n***Opção Inválida***\n\n");
                            goto voltaLogin;
                            break;
                        }
            }
        }
        return 0;
    }


    int menuInicial()
    {
        while(1)
        {
            int op;

            system("cls");
            system("color 1F");//DEFINE A COR  TIPO
            printf("\t                                                                                 \n");
            printf("\t+===============================================================================+\n");
            printf("\t*........PPPPPPPP.....II....MMM........MMM.....11....VV...............VV........*\n");
            printf("\t*........PP.....PP..........MM.MM.....MMMM.....11.....VV.............VV.........*\n");
            printf("\t*........PP.....PP....II....MM..MM...MM.MM.....11......VV...........VV..........*\n");
            printf("\t*........PP.....PP....II....MM...MM.MM..MM.....11.......VV.........VV...........*\n");
            printf("\t*........PPPPPPPP.....II....MM....MMM...MM.....11........VV.......VV............*\n");
            printf("\t*........PP...........II....MM.....M....MM.....11.........VV.....VV.............*\n");
            printf("\t*........PP...........II....MM..........MM.....11..........VV...VV..............*\n");
            printf("\t*........PP...........II....MM..........MM.....11............VVV................*\n");
            printf("\t*........PP...........II....MM..........MM.....11.............V.................*\n");
            printf("\t*...............................................................................*\n");
            printf("\t+===============================================================================+\n");
            printf("\t*                                                                               *\n");
            printf("\t*               1 - Cadastrar paciente              2 - Consultar               *\n");
            printf("\t*                                                                               *\n");
            printf("\t*                                  0 - SAIR                                     *\n");
            printf("\t*                                                                               *\n");
            printf("\t+===============================================================================+*\n");
            printf("\t*                             Introduza a opcao:                                 *\n");


            while(!scanf("%d",&op))
            {
            while(getchar()!='\n')
                {
                printf("\n");
                printf("             Atenção ! Voce digitou uma letra, o sistema so aceita numeros !\n");
                printf("             -------------------------------------------------------------\n");
                }
            }
        switch(op)
           {
            case 1:
            {
                cadastro();
                break;
            }

            case 2:
            {
                consulta();
                break;
            }

            case 0:
            {
                 exit(1);
            }

            default:
                {
                  printf("\n\n");
                  printf("             *** AVISO ***                   \n\n");
                  printf("             Opção invalida ! Por favor, tente outra opção. \n");
                  printf("             ---------------------------------------------- \n\n\n");
                  system("pause");
                  system("cls");
                  break;
                }
          }
        }
          return 1;
    }


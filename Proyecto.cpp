#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define TAM 10

using namespace std;

struct persona
{
    char nombre[20];
    long long int cedula;
    char ciudad [20];
    char pais[20];
    int edad;
    char sexo[10];
    char categoria;
    char tipo[20];
};
struct club
{
    string nombre;
    char ciudad[20];
    char provincia[20];
    int identificador;
    persona director;
    char contrasena[20];
};
///Funciones primarias
//----------------------------------------------------
void login();
void inicioadmin();
void pagadmin();
void iniciousuario(char usuario[20]);
void pagusuario(char usuario[20]);
///Validaciones
//-----------------------------------------------------
long long int validacionced(long long int cedula);
int validacionedad(int edad);
void separar(int v[],int tam,long long int cedula);
void mostrar(int v[],int tam);
void inicializar(int v[],int tam);
bool validar(int v[],int tam,int ultimo);
///Funciones secundarias
//-----------------------------------------------------
void buscar(char usuario3[20]);
void modificar(char usuario3[20],char usuario2[20]);
void eliminar(char usuario3[20]);
void crearclubs();
void crearjugadores(int num,char usuario3[20],char usuario2[20]);
void eliminarclubs();
void eliminarjugadores(char usuario3[20]);
void imprimirclubs();
void imprimir(char usuario4[20],char usuario2[20]);


int main ()
{
    login();
    return 0;
}
void login()
{
    char op,condi,usuario[20];
    do
    {
        cout<<"Bienvenido"<<endl;
        cout<<"Seleccione del siguiente menu la forma en que desea ingresar el programa"<<endl;
        cout<<"\t 1.Administrador"<<endl<<"\t 2.Usuario"<<endl<<"\t 3.Salir del Programa"<<endl;
        cin>>op;
        switch (op)
        {
            case '1':
                cout<<"Si se equivoco de opcion presione la tecla 0, Caso contrario oprima cualquier tecla"<<endl;
                fflush(stdin);
                condi = getchar();
                if(condi=='0')
                {
                    system("cls");
                }
                else
                {
                    condi=='1';
                    inicioadmin();
                }
                break;
            case '2':
                cout<<"Si se equivoco de opcion presione la tecla 0, Caso contrario oprima cualquier tecla"<<endl;
                cin>>condi;
                if(condi=='0')
                {
                    system("cls");
                }
                else
                {
                    condi=='1';
                    iniciousuario(usuario);
                }
                break;
            case '3':
                exit(1);
                break;
            default:
                cout<<"Error - Intente nuevamente"<<endl;
                condi='0';
                Sleep(500);
                system("cls");
        }
    }
    while(condi == '0');
}
void inicioadmin()
{
    string n_ingreso;
    string c_ingreso;
    string N_admin="administrador";
    string C_admin="admin";
    int cont=0;
    ofstream A_inciio();
    do
    {
        fflush(stdin);
        system("cls");
        cout<<"\nINGRESE NOMBRE DEL ADMIN:          ";
        getline(cin,n_ingreso);
        fflush(stdin);
        cout<<"\nINGRESE CONTRASEÑA DEL ADMIN:          ";
        getline(cin,c_ingreso);
        fflush(stdin);
        if(n_ingreso == N_admin && c_ingreso==C_admin)
        {
            cout<<"\n ADMINISTRADOR CORRECTO \n"<<endl<<endl<<"\t\t\tINICIANDO ";
            system("cls");
            pagadmin();
            system("cls");
        }
        else
        {
            cout<<endl<<"ADMIN INCORRECTO \n\n""INTENTE NUEVAMENTE !"<<endl;
            system("pause");
            fflush(stdin);
            cont++;
        }
        login();
    }while(cont<3);
    fflush(stdin);
    cout<<endl<<"SIN NUMERO DE INTENTOS !! "<<endl<<"SALIENDO DEL PROGRAMA"<<endl;
    Sleep(2000);
    exit(1);
}
void pagadmin()
{
    char op,condi;
    do
    {
        cout<<"Bienvenido administrador"<<endl;
        cout<<"Que deseas hacer hoy?"<<endl;
        cout<<"\t 1.Crear Clubs"<<endl<<"\t 2.Eliminar Club"<<endl<<"\t 3.Imprimir Clubs"<<endl<<"\t 4.Regresa al login"<<endl<<"\t 5.Salir"<<endl;
        cin>>op;
        switch (op)
        {
            case '1':
                crearclubs();
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                break;
            case '2':
                eliminarclubs();
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                break;

            case '3':
                imprimirclubs();
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                break;
            case '4':
                system("cls");
                login();
                break;
            case '5':
                exit(1);
                break;
            default:
                cout<<"Error - Intente nuevamente"<<endl;
                condi='0';
                Sleep(500);
                system("cls");

        }
    }
    while(condi == '0');

}
void crearclubs()
{
    int num,cedula,edad;
    cout<<"Cuantos clubs desea crear?"<<endl;
    cin>>num;
    system("cls");
    struct club clubs[num];
    for(int i=0;i<num;i++)
    {
        cout<<"Ingrese el nombre del club"<<endl;
        fflush(stdin);
        ofstream manejocontra;
        ofstream manejoequipo;
        getline(cin,clubs[i].nombre);
        manejocontra.open("C:\\Prueba\\contrasenas.txt",ios::app);
        cout<<"Ingrese la contrasena de usuario"<<endl;
        cin.getline(clubs[i].contrasena,20);
        manejocontra<<clubs[i].contrasena;
        manejocontra<<" ";
        manejocontra<<clubs[i].nombre;
        manejocontra<<endl;
        manejocontra.close();
        clubs[i].nombre=(clubs[i].nombre+".txt");
        manejoequipo.open(clubs[i].nombre.c_str(),ios::out);
        cout<<"Ingrese el numero de cedula del director"<<endl;
        cin>>clubs[i].director.cedula;
        cedula=clubs[i].director.cedula;
        cedula=validacionced(cedula);
        manejoequipo<<cedula;
        manejoequipo<<" ";
        cout<<"Ingrese la ciudad del equipo"<<endl;
        fflush(stdin);
        cin.getline(clubs[i].ciudad,20);
        strcat(clubs[i].ciudad," ");
        manejoequipo<<clubs[i].ciudad;
        strcpy(clubs[i].director.tipo,"Director");
        manejoequipo<<clubs[i].director.tipo;
        manejoequipo<<" ";
        cout<<"Ingrese el nombre del director"<<endl;
        strcat(clubs[i].director.nombre," ");
        fflush(stdin);
        cin.getline(clubs[i].director.nombre,20);
        manejoequipo<<clubs[i].director.nombre;
        cout<<"Ingrese la edad del director"<<endl;
        cin>>clubs[i].director.edad;
        edad=clubs[i].director.edad;
        edad=validacionedad(edad);
        manejoequipo<<" ";
        manejoequipo<<edad;
        manejoequipo<<" NoCat";
        manejoequipo<<endl;
        manejoequipo.close();
        system("cls");
    }
    cout<<"Club/s creado/s existosamente"<<endl;
}
long long int validacionced(long long int cedula)
{
    long long int cedu=0;
    int ced[TAM],ul,condi;
    bool valida;
    do
    {
        do
        {
            cedu=cedula;
            inicializar(ced,TAM);
            separar(ced,TAM,cedula);
        }
        while(((ced[0]*10)+(ced[1]))<1 || ((ced[0]*10)+(ced[1]))>24);
        ul=ced[9];
        valida=validar(ced,TAM,ul);
        if (valida)
        {
            return cedu;
        }
        else
        {
            cout<<"El numero de cedula esta errado o es falso"<<endl;
            cout<<"Ingrese nuevamente su cedula"<<endl;
            cout<<"Nota: El programa no continuara a menos que ingrese un numero de cedula valido"<<endl;
            cin>>cedula;
            condi = 1;

        }
    }
    while(condi == 1);
}
void separar(int v[],int tam,long long int cedula)
{
    for(int i=(tam-1);i>=0;i--)
    {
        v[i]=cedula%10;
        cedula=cedula/10;
    }
}
void mostrar(int v[],int tam)
{
    for(int i=0;i<=(tam-1);i++)
    {
        cout<<v[i]<<endl;
    }
}
void inicializar(int v[],int tam)
{
    int a;
    for(a=0;a<tam;a++)
    {
        v[a]=0;
    }
}
bool validar(int v[],int tam,int ultimo)
{
    int r1=0,suma=0,r2=0,suma3=0,res=0,digval=0,resul=0;
    for(int i=0;i<=8;i+=2)
    {
        r1=v[i]*2;
        if(r1>9)
        {
            r1=r1-9;
        }
        suma=r1+suma;

    }
    for(int i=1;i<=7;i+=2)
    {
        r2=r2+v[i];
    }
    suma=r2+suma;
    resul=suma;
    res=((suma/10)+1)*10;
    digval=res-resul;
    if (digval==10)
    {
        digval=0;
    }
    if (digval==ultimo)
    {
        return true;

    }
    else
    {
        return false;
    }

}
int validacionedad(int edad)
{
    int condi;
    do
    {
        if (edad<0 || edad>100)
        {
            cout<<"Edad fuera de rango"<<endl;
            cout<<"Ingrese nuevamente la edad del director"<<endl;
            cin>>edad;
            condi=0;
        }
        else
        {
            return edad;
        }
    }
    while(condi==0);
}
void eliminarclubs()
{
    string nombre;
    cout<<"Ingrese el nombre del club a eliminar"<<endl;
    fflush(stdin);
    getline(cin,nombre);
    nombre=nombre+".txt";
    if( remove(nombre.c_str()) != 0 )
    {
        cout<<"Error en la eliminacion"<<endl;
    }
    else
    {
        cout<<"Eliminado correctamente"<<endl;
    }

}
void imprimirclubs()
{
    string nombre,texto;
    cout<<"Ingrese el nombre del club a imprimir"<<endl;
    fflush(stdin);
    getline(cin,nombre);
    nombre=nombre+".txt";
    ifstream manejoclubs;
    manejoclubs.open(nombre.c_str(),ios::in);
    while(!manejoclubs.eof())
    {
        getline(manejoclubs,texto);
        cout<<texto<<endl;
    }
    manejoclubs.close();
}
void iniciousuario(char usuario[20])
{
    char contrasena[20],equipo[20];
    char usuario2[20];
    cout<<"Ingrese su nombre de usuario"<<endl;
    fflush(stdin);
    cin>>usuario;
    strcpy(usuario2,usuario);
    ifstream salida;
    salida.open("C:\\Prueba\\contrasenas.txt",ios::in);
    if(salida.fail())
    {
        cout<<"Error"<<endl;
    }
    else
    {
        char aux[20];
        int condi;
        cout<<"Ingrese su contrasena"<<endl;
        cin>>aux;

        salida>>contrasena;

        do
        {

            if(strcmp(aux,contrasena)==0)
            {
                salida>>equipo;
                cout<<"Correcto"<<endl;
                salida.close();
                system("cls");
                pagusuario(usuario2);
                system("cls");
                login();
            }
            else
            {
                cout<<"Error"<<endl;
                salida.close();
                system("cls");
                login();
            }

        }
        while(!salida.eof());
    }

}
void buscar(char nombrea[20])
{
    char nombre[20],profesion [20],cedula[10],ciudad[10],categoria[20];
    int edad;
    strcat(nombrea,".txt");
    ifstream salida;
    salida.open(nombrea,ios::in);
    if(salida.fail())
    {
        cout<<"Error"<<endl;
    }
    else
    {
        char aux[20];
        cout<<"Ingrese el numero de cedula"<<endl;
        cin>>aux;
        salida>>cedula;

        while(!salida.eof())
        {
            salida>>ciudad>>profesion>>nombre>>edad>>categoria;

            if(strcmp(aux,cedula)==0)
            {
                cout<<cedula<<" "<<ciudad<<" "<<profesion<<" "<<nombre<<" "<<edad<<" "<<categoria<<endl;
            }
        }
        salida.close();
    }
}
void modificar(char usuario3[20],char usuario2[20])
{
    int num;
    eliminar(usuario3);
    strcpy(usuario3,usuario2);
    num=1;
    crearjugadores(num,usuario3,usuario2);
}
void eliminar (char nombrea[20])
{
        char nombre[20],profesion [20],cedula[10],ciudad[10],categoria[20];
        int edad;
        strcat(nombrea,".txt");
        ifstream salida;
        salida.open(nombrea,ios::in);

        ofstream entrada;
        entrada.open("temp.txt",ios::out);

        if(salida.fail())
        {
            cout<<"Error"<<endl;
        }
        else
        {
           char aux[20];

           cout<<"Ingrese el numero de cedula"<<endl;
           cin>>aux;

           salida>>cedula;

           while(!salida.eof())
           {
               salida>>ciudad>>profesion>>nombre>>edad>>categoria;

               if(strcmp(aux,cedula)==0)
               {
                   cout<<"Eliminado"<<endl;
                   getch();
               }
               else
               {
                   entrada<<cedula<<" "<<ciudad<<" "<<profesion<<" "<<nombre<<" "<<edad<<" "<<categoria<<endl;

               }

               salida>>cedula;
           }
           entrada.close();
           salida.close();

           remove(nombrea);
           rename("temp.txt",nombrea);
        }

}
void pagusuario(char usuario2[20])
{
    int op,condi;
    char usuario3[20],usuario4[20];
    strcpy(usuario3,usuario2);
    strcpy(usuario4,usuario2);
    do
    {
        cout<<"Bienvenido usuario"<<endl;
        cout<<"Que deseas hacer hoy?"<<endl;
        cout<<"\t 1.Crear Jugadores"<<endl<<"\t 2.Eliminar Jugadores"<<endl<<"\t 3.Imprimir Lista de jugadores"<<endl<<"\t 4.Modificar Jugadores"<<endl<<"\t 5.Regresar al Login"<<endl<<"\t 6.Salir"<<endl;
        cin>>op;
        switch (op)
        {
            case 1:
                int num;
                cout<<"Cuantos jugadores desea crear?"<<endl;
                cin>>num;
                crearjugadores(num,usuario3,usuario2);
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                system("cls");
                break;
            case 2:
                eliminarjugadores(usuario4);
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                system("cls");
                break;
            case 3:
                imprimir(usuario4,usuario2);
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                system("cls");
                break;
            case 4:
                modificar(usuario3,usuario2);
                cout<<"Desea volver al menu?"<<endl;
                cout<<"\t 0.Si"<<endl<<"\t 1.No"<<endl;
                cin>>condi;
                system("cls");
                break;
            case 5:
                login();
                break;
            case 6:
                exit(1);
                break;
            default:
                cout<<"Error"<<endl;
                condi == 0;
                system("cls");
        }
    }
    while(condi==0);
}
void crearjugadores(int num,char usuario3[20],char usuario2[20])
{
    struct persona jugadores[num];
    long long int cedula;
    int edad;
    for(int i=0;i<num;i++)
    {
        ofstream manejojugadores;
        strcat(usuario3,".txt");
        manejojugadores.open(usuario3,ios::app);
        cout<<"Ingrese el numero de cedula del jugador"<<endl;
        cin>>jugadores[i].cedula;
        cedula=jugadores[i].cedula;
        cedula=validacionced(cedula);
        manejojugadores<<cedula;
        manejojugadores<<" ";
        cout<<"Ingrese la ciudad del jugador"<<endl;
        fflush(stdin);
        cin.getline(jugadores[i].ciudad,20);
        strcat(jugadores[i].ciudad," ");
        manejojugadores<<jugadores[i].ciudad;
        strcpy(jugadores[i].tipo,"Jugador");
        manejojugadores<<jugadores[i].tipo;
        manejojugadores<<" ";
        cout<<"Ingrese el nombre del jugador"<<endl;
        strcat(jugadores[i].nombre," ");
        fflush(stdin);
        cin.getline(jugadores[i].nombre,20);
        manejojugadores<<jugadores[i].nombre;
        cout<<"Ingrese la edad del jugador"<<endl;
        cin>>jugadores[i].edad;
        edad=jugadores[i].edad;
        edad=validacionedad(edad);
        manejojugadores<<" ";
        manejojugadores<<edad;
        if(edad<18)
        {
            jugadores[i].categoria='J';
            manejojugadores<<" Juvenil";
        }
        else
        {
            jugadores[i].categoria='S';
            manejojugadores<<" Sennior";
        }
        manejojugadores<<endl;
        manejojugadores.close();
        strcpy(usuario3,usuario2);
        system("cls");
    }
}
void eliminarjugadores(char usuario3[20])
{
    eliminar(usuario3);
}
void imprimir(char usuario4[20],char usuario2[20])
{
    ifstream imprimir;
    string texto;
    strcat(usuario4,".txt");
    imprimir.open(usuario4,ios::in);
    while(!imprimir.eof())
    {
        getline(imprimir,texto);
        cout<<texto<<endl;
    }
    imprimir.close();
    strcpy(usuario4,usuario2);
}

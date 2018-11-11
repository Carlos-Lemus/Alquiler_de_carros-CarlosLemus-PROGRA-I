//Hecho por Carlos Alfonso Lemus Rodezno

//Programa de alquiler de autos

#include <iostream> //libreria estandar de  c++ para utilizar sus funciones
#include <conio.h> //Para utilizar sus funciones
#include <windows.h> //Para utilizar sus funciones
#include <cstring> //Para utilizar sus funciones
#include <stdio.h> //Para utilizar sus funciones
#include <windows.h> //Para utilizar sus funciones

using namespace std; //esta linea nos permite reducir las lineas del codigo

void menu(bool c[]); //decclaracion de funcion

void cliente(); //declaracion de funcion cliente
void agregarc(bool c[]); //declaracion de funcion que agregara los carros alquilados para visualizarlos en la funcion
void carros(); //declaracion que rellenara los datos de los carros
void mostrarc(bool c[]); //declaracion q nos permitira visualizar 
void gotoxy(int x, int y); //declaracion de funcion gotoxy
void cargar(); //declaracion de funcion que permite dar un tiempo de carga
void clear(); //declaracion de funcion que limpia la pantalla de los textos
void errordato(); //declaracion de funcion que evita que se ingrese datos incorrectos
void aux(int *aux[6]);

//estructura que contiene los datos de clientes
struct datoscli{

    char nombre[51];
    char apellido[51];
    int dui;
    char direccion[61];
    int telefono;

};

//estructura para los datos de los carros
struct datoscar{

	//Declaracion de variables
    char modelo[31];
    char num_chasis[31];
    float precio;
    int anio;
    char disenio[21];
    char transmision[21];
    char nombre[30]; //

	//funcion que inicializara las variables de las estructura
    void inicializar(char *m, char *nc, float p,int a, char *d, char *t,char *n)
    {
        strcpy(modelo,m);
        strcpy(num_chasis, nc);
        precio = p;
        anio = a;
        strcpy(disenio, d);
        strcpy(transmision, t);
		strcpy(nombre,n);

    };
	
	//declaracion de funciones para visualizar los carros elejidos
    void mostrar();
    void mostrarNombre();

}carro[6];

//estructura datoscar utilizada para acceder a la funcion mostrarNombre que esta dentro de esta estructura atravez del operador de resolucion
void datoscar::mostrarNombre(){
	
	gotoxy(44,1);
    cout << "---------------------";
	gotoxy(44,2);
    cout << "| Carros alquilados |" << endl;
    gotoxy(44,3);
	cout << "---------------------" << endl;
	
	gotoxy(43,5);
	//se imprime el nombre del vehiculo
	cout << nombre << endl;
	
	system("pause"); //se apusa el programa hasta presionar un boton
}

//cuerpo principal del programa
int main()
{
	//funcion para añadir color a la letra y fondo de la consola
	system("color 4B");
	
	cout << '\a'; // funcion que reproduce un sonido de campana
	
	gotoxy(43,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "-----------------------------------" << endl;
	gotoxy(43,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "|                                 |" << endl;
	gotoxy(43,5); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "|     ****  *  * **** **** *      |" << endl;
	gotoxy(43,6); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "|     **     **  *    **   *      |" << endl;
	gotoxy(43,7); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "|     ****  *  * **** **** ****   |" << endl;
	gotoxy(43,8); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "|                                 |" << endl;
	gotoxy(43,9); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << "---------------------------------" << endl;
	
	cargar();
	
	bool comprobar[6]  = {false,false,false,false,false,false};
    menu(comprobar);

	
    return 0;
}

//funcion menu para mostrar y elejir las opciones del programa
void menu(bool c[]) {
    int opcion;
	
	carros();
	
	do{
		
		clear();
		
		gotoxy(43,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "************************************" << endl;
		gotoxy(43,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*                                  *" << endl;
		gotoxy(43,5); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*            Bienvenido            *" << endl;
		gotoxy(43,6); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*       Alquila tu carro hoy       *" << endl;
		gotoxy(43,7); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*                                  *" << endl;
		gotoxy(43,8); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "************************************" << endl;
			
		gotoxy(43,11);
	    cout << "Menu" << endl;
	    gotoxy(43,12);
	    cout << "1.Mostrar carros" << endl;
	    gotoxy(43,13);
	    cout << "2.Agregar cliente" << endl;
	    gotoxy(43,14);
	    cout << "3.Agregar carro" << endl;
	    gotoxy(43,15);
		cout << "4.Salir" << endl;
	
	    fflush(stdin);
	    gotoxy(43,17);
	    cout << "Elija un opcion: ";
	    cin >> opcion;
	    errordato();
    } while(opcion < 1 || opcion >4);

    switch(opcion){
        case 1:
            clear();
            mostrarc(c);
            break;
        case 2:
            clear();
            cliente();
            break;
        case 3:
            clear();
            agregarc(c);
            break;
        default:
            clear();
            gotoxy(43,11);
            cout << "Gracias por usar el programa" << endl;

    }
    system("pause");
}

void cliente() //funcion sin retorno y sin parametros se utilizara para ingresar y mostrar los datos del cliente
{
	datoscli usuario; //varaible usuario de tipo de estructura datoscli
	
	//Ciclo do while que evitara la entrada de datos erroneos
    do{
    	clear();
		
		gotoxy(48,3);
		cout << "-----------------" << endl;
		gotoxy(48,4);
		cout << "| Datos cliente |" << endl;
		gotoxy(48,5);
		cout << "-----------------" << endl;
		
		gotoxy(43,7);
        cout << "Ingrese los siguientes datos" << endl;

		fflush(stdin); //funcion que limpia el buffer
		gotoxy(43,9);
        cout << "Nombre: ";
        cin.getline(usuario.nombre, 51);
        errordato();
		
		fflush(stdin);  //funcion que limpia el buffer
		gotoxy(43,10);
        cout << "Apellidos: ";
        cin.getline(usuario.apellido, 51);
        errordato();
		
		fflush(stdin);  //funcion que limpia el buffer
		gotoxy(43,11);
        cout << "DUI: ";
        cin >> usuario.dui;
        errordato();
		
		fflush(stdin);  //funcion que limpia el buffer
		gotoxy(43,12);
        cout << "Dirrecion: ";
        cin.getline(usuario.direccion, 61);
        errordato();

		fflush(stdin);  //funcion que limpia el buffer
		gotoxy(43,13);
        cout << "Telefono: ";
        cin >> usuario.telefono;
        errordato();

    }while(cin.fail());
	
	//se imprime los datos ingresados
	gotoxy(48,3);
	cout << "-----------------" << endl;
	gotoxy(48,4);
	cout << "| Datos cliente |" << endl;
	gotoxy(48,5);
	cout << "-----------------" << endl;
		
	gotoxy(43,7);
    cout << "Ingrese los siguientes datos" << endl;

	gotoxy(43,9);
    cout << "Nombre: " << usuario.nombre;
        
	gotoxy(43,10);
	cout << "Apellidos: " << usuario.apellido;
		
	gotoxy(43,11);
    cout << "DUI: " << usuario.dui;
		
	gotoxy(43,12);
    cout << "Dirrecion: " << usuario.direccion;

	gotoxy(43,13);
    cout << "Telefono: " << usuario.telefono << endl;
	
    system("pause");
    
    main();
    
}

void carros() //funcion que le asignara los respectivos datos a los carros
{
    carro[0].inicializar("CERATO", "2H2TA59BWDY987665", 8016.00, 2010, "Sedan", "Manual","1.KIA CERATO");
    carro[1].inicializar("SPORTERO", "1GNCS13Z6MP246789", 26327.00, 2016, "Pick-up", "Automatica","2.MITSUBISHI SPORTERO");
    carro[2].inicializar("CORROLLA", "3G1J85CC2GS999589", 13812.00,2012, "Sedan", "Automatica","3.TOYOTA COROLLA");
    carro[3].inicializar("PATHFINDER", "1HGBH41JXMN109186", 11896.00, 2002, "CAMIONETA", "Automatica","4.NISSAN PATHFINDER");
    carro[4].inicializar("320 I", "2JECS4305UB999124", 8993.00, 2007, "Sedan", "Automatica", "5.BMW 320 I");
    carro[5].inicializar("YARIS", "4JHLRD7874C026456", 14823.00, 2017, "Sedan", "Automatica","6.TOYOYA YARIS");

}

void datoscar::mostrar()	/*se accedera a la funcion mostrar que esta en la estructura datoscar() por medio del operador de diferenciacion
							esta funcion imprimira los datos de los carros*/	
{
	//se imprime los datos de los carros
	gotoxy(44,1);
    cout << "-------------------";
	gotoxy(44,2);
    cout << "| Carro alquilado |" << endl;
    gotoxy(44,3);
	cout << "-------------------" << endl;
	gotoxy(43,5);
    cout << "Modelo: " << modelo << endl;
    gotoxy(43,6);
	cout << "Numero de Chasis: " << num_chasis << endl;
    gotoxy(43,7);
	cout << "Precio: $" << precio << endl;
    gotoxy(43,8);
	cout << "Fecha de salida: " << anio << endl;
    gotoxy(43,9);
	cout << "Diseño: " << disenio << endl;
    gotoxy(43,10);
	cout << "Transmision: " << transmision << endl;
    
    system("pause"); //detiene la pantalla hasta que se presione una tecla
}

void agregarc(bool c[]) //funcion que no retorna valor contiene un parametro de tipo bool sera utilizada para elejir el carroa alquilar
{

    int opccar; //variable utilizada para elejir una opcion disponible
	
	//Ciclo de do-while utilizado para evitar numeros negativos y erroees de ingreso de datos
    do{
    	
    	gotoxy(48,1);
    	cout << "------------";
		gotoxy(48,2);
        cout << "| Opciones |" << endl;
        gotoxy(48,3);
		cout << "------------" << endl;
        gotoxy(15,5);
		cout << "1.KIA CERATO" << endl;
        gotoxy(40,5);
		cout << "2.MITSUBISHI SPORTERO" << endl;
        gotoxy(70,5);
		cout << "3.TOYOTA COROLLA" << endl;
        gotoxy(15,7);
		cout << "4.NISSAN PATHFINDER" << endl;
        gotoxy(40,7);
		cout << "5.BMW 320 I" << endl;
        gotoxy(70,7);
		cout << "6.TOYOYA YARIS" << endl;

		fflush(stdin);  //funcion que limpia el buffer
		gotoxy(48,9);
        cout << "Elije un carro: ";
        cin >> opccar;

    } while(opccar < 1 || opccar > 6);

    clear(); //funcion que limpia la pantalla
    
    /*se debe aclarar que la linea carro[opccar - 1].mostrar(); significa que atravez de la variable de estructura dimensional carro[]
    se accede a la funcion mostrar() que esta dentro de la estructura datoscar
	Luego la condicion es utilizada para saber si el carro ya habia escogido en caso que aparecera en la opcion mostrar carros
	en caso que si mostrar una impresion que informara al usuario que ya se ha seleccionado*/
    if(!c[opccar-1]){
    	carro[opccar - 1].mostrar();
    	c[opccar-1] = true;
	}else {
		gotoxy(48,5);
		cout << "El Carro ya a sido selecionado :(, elije otro" << endl;
	}
    
    //Setencia switch para abrir la imagen correspondiente a la opcion de carro elejida
    switch(opccar){
    	case 1:
    		system("KIA_CERATO.bmp"); //funcio para abrir la imagen del auto atravez del explorador
    		break;
    	case 2:
    		system("MITSUBISHI_SPORTERO.bmp"); //funcio para abrir la imagen del auto atravez del explorador
    		break;
    	case 3:
    		system("TOYOTA_COROLLA.bmp"); //funcio para abrir la imagen del auto atravez del explorador
    		break;
    	case 4:
    		system("NISSAN_PATHFINDER.bmp"); //funcio para abrir la imagen del auto atravez del explorador
    		break;
    	case 5:
    		system("BMW_320_I.bmp"); //funcio para abrir la imagen del auto atravez del explorador
    		break;
    	default:
    		system("TOYOYA_YARIS.bmp"); //funcio para abrir la imagen del auto atravez del explorador
	}
    
    system("pause"); //detiene la pantalla hasta que se presione una tecla
    menu(c); //una vez terminada la instrucciones de la funcion se dirijira al usuario devuelta al emnu 

}

/*funcion sin retorna esta funcion evaluara comprobar[6]  y comprabara si true este llamara a la funcion mostrarnombre que imprime el nombre
del vehiculo*/
void mostrarc(bool c[])
{
	//ciclo for para evaluar la variable dimensional comprobar
		for(int i=0;i<6;i++){
			if(c[i]) { //si la condicion es verdadera si ingresara caso contrario se saltara esta linea
				carro[i].mostrarNombre(); //se llama a la funcion mostrarnombre()
			}
		}
		menu(c);
}

void gotoxy(int x, int y) //funcion para poder colocar el texto de la pantalla en cualquier parte
{
	//Estas instrucciones permiticra ubicar un texto en el lugar que se desee en la pantalla
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cargar() //funcion que permite dar un tiempo de carga
{

	//Variable cargar servira como contador
	int carga = 1;

	cout << "\nEl programa esta cargando" << endl;

	//ciclo while para generar un tiempo de carga
	do {
		//Funcion Sleep para permite generar un tiempo de carga
		Sleep(1400);

		cout << "....";

		//Variable carga se utiliza como contador
		carga++;

	} while (carga < 4);
}

void clear() //Funcion que permite limpiar la pantalla
{
	//funcion system("cls") que limpia la pantalla de los textos que esta contiene
	system("cls");
}

void errordato() //funcion que evita que se ingrese datos incorrectos
{
		//Ciclo while paraevitar datos incorrectos
		while(cin.fail()){

		//Limpia el buffer de los datos ingresados
		cin.clear();

		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');

		}
}



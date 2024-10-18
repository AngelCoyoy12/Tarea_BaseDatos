create database equipo;
use equipo;

CREATE table jugadores(

ID_jugador int primary key auto_increment ,

Nombre varchar (50),

Apellido varchar (50),

edad int,

NumeroCamiseta int,

equipo varchar(50)

);
 
CREATE table patrocinadores(

ID_prs int primary key auto_increment,

Nombre varchar (50),

Dir_patrocinio varchar (50),

Can_inversion int

);
 
 
insert into jugadores(Nombre, Apellido, edad, NumeroCamiseta,equipo)

values('Lebron','James',25,19,'Lakers');
 
insert into patrocinadores(Nombre, Dir_patrocinio, Can_inversion)

values('Megapaca','Gerardo Reyes',100000);
 
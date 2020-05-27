# presente

Low budget game for LP

(ﾉ*ФωФ)ﾉ

```
 /\_/\
( o.o )
 > ^ <
```

<(0w0)>

                   .               ,.
                  T."-._..---.._,-"/|
                  l|"-.  _.v._   (" |
                  [l /.'_ \; _~"-.`-t
                  Y " _(o} _{o)._ ^.|
                  j  T  ,-<v>-.  T  ]
                  \  l ( /-^-\ ) !  !
                   \. \.  "~"  ./  /c-..,__
                     ^r- .._ .- .-"  `- .  ~"--.
                      > \.                      \
                      ]   ^.                     \
                      3  .  ">            .       Y  -Row
         ,.__.--._   _j   \ ~   .         ;       |
        (    ~"-._~"^._\   ^.    ^._      I     . l
         "-._ ___ ~"-,_7    .Z-._   7"   Y      ;  \        _
            /"   "~-(r r  _/_--._~-/    /      /,.--^-._   / Y
            "-._    '"~~~>-._~]>--^---./____,.^~        ^.^  !
                ~--._    '   Y---.                        \./
                     ~~--._  l_   )                        \
                           ~-._~~~---._,____..---           \
                               ~----"~       \
                                              \


```
.       .
 |\_---_/|
/   o_o   \
|    U    |
\  ._I_.  /
 `-_____-'
```

Hola Buenas, para empezar, modifiqué la feature Marcador de puntaje y musica(#10). En lo cual modifiqué el main, state.c y state.h, ademas de crear el files.c y files.h.

Empezando por la musica, utilicé 4 pistas sin copyright, una de fondo, otra al ganar, otra al perder y otra de los disparos. Para hacer esto me base en los ejemplos de raylib. Pero no las coloqué reproduciendo todo el while, le coloque un if, si la cantidad de enemigos es distinta de cero, se puede jugar y toca la de fondo, el else if: si el hp=0, sale un mensaje en grande de GAME OVER, y suena su respectiva canción, pero como en esta feature no se manipula el hp, no la pude revisar si funcionaba. y el else es de victoria, donde sale su respectivo mensaje y musica. Y en cada disparo suena un sonido caracteristico del galaga.

El otro punto de esta feature es el contador de puntaje, el cual no inicie en el main como puntero, justo antes del while, y lo coloqué como tercer parametro del state_update, por lo que modifiqué el state.c y state.h. Pero la parte especifica fue en el check bullet, donde coloque un if, pero mi modo de verlo es, por cada disparo al enemigo aumente el contador, entonces para matar a un enemigo pequeño, se necesitan 2 disparos, entonces el contador aumenta 2 veces, de la misma forma el otro enemigo. Y voy mostrando por pantalla la puntuación. Lo que si, como en mi feature no cambia el hp, no se sabe cuando muere uno, asi que asumo como cuando se mata a todos los enemigos el fin del juego. y por eso el histore.txt almacena en esos 2 casos, cuando se gane o cuando se pierda. 

Para complementar el histore.txt, la funcion se ejecuta cuando se gane o se pierda, para que tenga un chiste en esta feature. lo primero que hago es comprobar si existe un histore.txt, por lo que abro un .txt con extensión "a", para que asi si existe, bien, pero si no, que cree uno vacio. Luego lo leo, guardo el valor, y lo comparo con la puntuación actual, si es mayor la actual, se sobreescribe con "w", y si no ,no hay cambios.

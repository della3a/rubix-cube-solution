/*Rubix Cube*/

/*;==========================================
  ; Title:  Rubix Cube Solution
  ; Author: Manel Kheffache & Bilal Si Said
  ; Date:   8 Feb 2022
  ;========================================== */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//declaration d'une structure qui contient des tableaux
typedef struct cube{
    int tabR[2][2];
    int tabO[2][2];
    int tabV[2][2];
    int tabB[2][2];
    int tabJ[2][2];
    int tabBC[2][2];
}CubeDeRubik;

//fonction qui affiche l'etat actuel du cube de rubik
CubeDeRubik * affichagecube(CubeDeRubik *cube){
    printf("\n");

        // afficher bleu
        printf("bleu");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabB[i][j]);

            }
        }
        printf("\n");

        //afficher jaune
        printf("\n");
        printf("jaune");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabJ[i][j]);
            }
        }
        printf("\n");

        //afficher orange
        printf("\n");
        printf("orange");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabO[i][j]);
            }
        }
        printf("\n");

        //afficher rouge
        printf("\n");
        printf("rouge");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabR[i][j]);
            }
        }
        printf("\n");

        //afficher blanc
        printf("\n");
        printf("blanc");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabBC[i][j]);
            }
        }
        printf("\n");

        //afficher vert
        printf("\n");
        printf("vert");
        for (int i=0; i<2; i++){
            printf("\n");
            for(int j=0; j<2; j++){
                printf("%d",cube->tabV[i][j]);
            }
        }
        printf("\n");
        return cube;
}

//les rotations

//rotation droite
CubeDeRubik * RD(CubeDeRubik *cube){
    //premiere partie
    int mat1[2][2];
    for(int i=0; i<2; i++){
        mat1[i][1]=cube->tabR[0][i];
        mat1[i][0]=cube->tabR[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabR[i][j]=mat1[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[i][1];
        mat2[i][1]=cube->tabV[i][1];
        mat2[i][2]=cube->tabJ[i][1];
        mat2[i][3]=cube->tabB[i][0];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[i][1]=mat2[i][1];
        cube->tabV[i][1]=mat2[i][2];
        cube->tabJ[1-i][1]=mat2[i][3];
        cube->tabB[1-i][0]=mat2[i][0];
    }

    return cube;
}

//rotation gauche
CubeDeRubik * RG(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[i][1]=cube->tabO[0][i];
        mat[i][0]=cube->tabO[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabO[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[i][0];
        mat2[i][1]=cube->tabV[i][0];
        mat2[i][2]=cube->tabJ[i][0];
        mat2[i][3]=cube->tabB[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[1-i][0]=mat2[i][3];
        cube->tabV[i][0]=mat2[i][0];
        cube->tabJ[i][0]=mat2[i][1];
        cube->tabB[1-i][1]=mat2[i][2];
    }
    return cube;
}

//rotation du haut du cube
CubeDeRubik * Renhaut(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[i][1]=cube->tabBC[0][i];
        mat[i][0]=cube->tabBC[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabBC[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabO[0][i];
        mat2[i][1]=cube->tabV[0][i];
        mat2[i][2]=cube->tabR[0][i];
        mat2[i][3]=cube->tabB[0][i];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabO[0][i]=mat2[i][1]; //
        cube->tabV[0][i]=mat2[i][2]; //
        cube->tabR[0][i]=mat2[i][3]; //
        cube->tabB[0][i]=mat2[i][0]; //
    }
    return cube;
}

//rotation du bas du cube
CubeDeRubik * Renbas(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[i][1]=cube->tabJ[0][i];
        mat[i][0]=cube->tabJ[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabJ[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabO[1][i];
        mat2[i][1]=cube->tabV[1][i];
        mat2[i][2]=cube->tabR[1][i];
        mat2[i][3]=cube->tabB[1][i];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabO[1][i]=mat2[i][3]; //
        cube->tabV[1][i]=mat2[i][0]; //
        cube->tabR[1][i]=mat2[i][1]; //
        cube->tabB[1][i]=mat2[i][2]; //
    }
    return cube;
}

//rotation front
CubeDeRubik * RF(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[i][1]=cube->tabV[0][i];
        mat[i][0]=cube->tabV[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabV[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[1][i];
        mat2[i][1]=cube->tabR[i][0];
        mat2[i][2]=cube->tabJ[0][i];
        mat2[i][3]=cube->tabO[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[1][1-i]=mat2[i][3]; //
        cube->tabR[i][0]=mat2[i][0]; //
        cube->tabJ[0][1-i]=mat2[i][1]; //
        cube->tabO[i][1]=mat2[i][2]; //
    }
    return cube;
}

//rotation back
CubeDeRubik * RB(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[i][1]=cube->tabB[0][i];
        mat[i][0]=cube->tabB[1][i];
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabB[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[0][i];
        mat2[i][1]=cube->tabO[i][0];
        mat2[i][2]=cube->tabJ[1][i];
        mat2[i][3]=cube->tabR[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[0][i]=mat2[i][3]; //
        cube->tabO[1-i][0]=mat2[i][0]; //
        cube->tabJ[1][i]=mat2[i][1]; //
        cube->tabR[1-i][1]=mat2[i][2]; //
    }
    return cube;
}

//les rotations prime

//rotation droite prime
CubeDeRubik * RDP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabR[0][i];
        mat[1-i][1]=cube->tabR[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabR[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[i][1];
        mat2[i][1]=cube->tabV[i][1];
        mat2[i][2]=cube->tabJ[i][1];
        mat2[i][3]=cube->tabB[i][0];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[1-i][1]=mat2[i][3];
        cube->tabV[i][1]=mat2[i][0];
        cube->tabJ[i][1]=mat2[i][1];
        cube->tabB[1-i][0]=mat2[i][2];
    }

    return cube;
}

//rotation gauche prime
CubeDeRubik * RGP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabO[0][i];
        mat[1-i][1]=cube->tabO[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabO[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[i][0];
        mat2[i][1]=cube->tabV[i][0];
        mat2[i][2]=cube->tabJ[i][0];
        mat2[i][3]=cube->tabB[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[i][0]=mat2[i][1];
        cube->tabV[i][0]=mat2[i][2];
        cube->tabJ[1-i][0]=mat2[i][3];
        cube->tabB[1-i][1]=mat2[i][0];
    }
    return cube;
}

//rotation du haut du cube prime
CubeDeRubik * RenhautP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabBC[0][i];
        mat[1-i][1]=cube->tabBC[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabBC[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabO[0][i];
        mat2[i][1]=cube->tabV[0][i];
        mat2[i][2]=cube->tabR[0][i];
        mat2[i][3]=cube->tabB[0][i];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabO[0][i]=mat2[i][3]; //
        cube->tabV[0][i]=mat2[i][0]; //
        cube->tabR[0][i]=mat2[i][1]; //
        cube->tabB[0][i]=mat2[i][2]; //
    }
    return cube;
}

//rotation du bas du cube
CubeDeRubik * RenbasP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabJ[0][i];
        mat[1-i][1]=cube->tabJ[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabJ[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabO[1][i];
        mat2[i][1]=cube->tabV[1][i];
        mat2[i][2]=cube->tabR[1][i];
        mat2[i][3]=cube->tabB[1][i];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabO[1][i]=mat2[i][1]; //
        cube->tabV[1][i]=mat2[i][2]; //
        cube->tabR[1][i]=mat2[i][3]; //
        cube->tabB[1][i]=mat2[i][0]; //
    }
    return cube;
}

//rotation face avant de cube
CubeDeRubik * RFP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabV[0][i];
        mat[1-i][1]=cube->tabV[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabV[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[1][i];
        mat2[i][1]=cube->tabR[i][0];
        mat2[i][2]=cube->tabJ[0][i];
        mat2[i][3]=cube->tabO[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[1][i]=mat2[i][1]; //
        cube->tabR[1-i][0]=mat2[i][2]; //
        cube->tabJ[0][i]=mat2[i][3]; //
        cube->tabO[1-i][1]=mat2[i][0]; //
    }
    return cube;
}

//rotation face arriere du cube
CubeDeRubik * RBP(CubeDeRubik *cube){
    //premiere partie
    int mat[2][2];
    for(int i=0; i<2; i++){
        mat[1-i][0]=cube->tabB[0][i];
        mat[1-i][1]=cube->tabB[1][i];

    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cube->tabB[i][j]=mat[i][j];
        }
    }
    //deuxieme partie
    int mat2[2][4];
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
        mat2[i][0]=cube->tabBC[0][i];
        mat2[i][1]=cube->tabO[i][0];
        mat2[i][2]=cube->tabJ[1][i];
        mat2[i][3]=cube->tabR[i][1];
        }
    }
    for (int i=0; i<2; i++){
        cube->tabBC[0][1-i]=mat2[i][1]; //
        cube->tabO[i][0]=mat2[i][2]; //
        cube->tabJ[1][1-i]=mat2[i][3]; //
        cube->tabR[i][1]=mat2[i][0]; //
    }
    return cube;
}

CubeDeRubik * RANDOM(CubeDeRubik *cube){
    printf("Apres le Random: ");
    int aleatoire = 0;
    srand(time(NULL));
    for(int i=0; i<18; i++){
    aleatoire=(rand()%11+1);
    switch(aleatoire){
        case 1 : cube = RD(cube);
                 printf("R ");
        break;
        case 2 : cube = RG(cube);
                 printf("L ");
        break;
        case 3 : cube = Renhaut(cube);
                 printf("U ");
        break;
        case 4 : cube = Renbas(cube);
                 printf("D ");
        break;
        case 5 : cube = RF(cube);
                 printf("F ");
        break;
        case 6 : cube = RB(cube);
                 printf("B ");
        break;
        case 7 : cube = RDP(cube);
                 printf("RP ");
        break;
        case 8 : cube = RGP(cube);
                 printf("LP ");
        break;
        case 9 : cube = RenhautP(cube);
                 printf("UP ");
        break;
        case 10 : cube = RenbasP(cube);
                 printf("DP ");
        break;
        case 11 : cube = RFP(cube);
                 printf("FP ");
        break;
        case 12 : cube = RBP(cube);
                 printf("BP");
        break;
        default:
                printf("Aucune rotation faite");
        break;
    }

    }
    return cube;

}

/*CubeDeRubik * FaceBlanche(CubeDeRubik *cube){
while(cube.tabBC[0][0] != 6 || cube.tabBC[0][1] != 6 || cube.tabBC[1][0] != 6 || cube.tabBC[1][1] != 6){

    if(cube.tabO[1][0] == cube.tabBC[1][0]){
        RGP(&cube);
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
    }
    if(cube.tabV[0][0] == cube.tabBC[1][0]){
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
    }
    if(cube.tabJ[1][1] == cube.tabBC[1][0]){
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
        RG(&cube);
        RG(&cube);
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
    }
    if(cube.tabO[1][1] == cube.tabBC[1][0]){
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
        RGP(&cube);
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
    }
    if(cube.tabV[0][1] == cube.tabO[1][0]){
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
        RG(&cube);
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
    }
    if(cube.tabB[0][1] == cube.tabO[1][0]){
        RDP(&cube);
        RDP(&cube);
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
        RG(&cube);
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);

    }
    if(cube.tabB[1][1] == cube.tabO[1][0]){
        RDP(&cube);
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
        RGP(&cube);
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);
    }
    if(cube.tabB[0][0] == cube.tabO[1][0]){
        RG(&cube);
        RG(&cube);
        RenbasP(&cube);
        RGP(&cube);
        Renbas(&cube);
    }
     if(cube.tabB[1][0] == cube.tabO[1][0]){
        RG(&cube);
        RGP(&cube);
        RenbasP(&cube);
        RG(&cube);
        Renbas(&cube);

     }




}
}*/

CubeDeRubik *faceBlanche(CubeDeRubik *cube)
{
    printf("\nFace blanche : ");
    while(cube->tabBC[0][0]!=5||cube->tabBC[0][1]!=5||cube->tabBC[1][0]!=5||cube->tabBC[1][1]!=5)
    {
        if(cube->tabV[0][0]==5){
            if(cube->tabBC[1][0]==1&&cube->tabO[0][1]==2){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabO[0][1]==3&&cube->tabBC[1][0]==2){
                RenhautP(cube);printf("enHautP ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabO[0][1]==4&&cube->tabBC[1][0]==3){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabO[0][1]==1&&cube->tabBC[1][0]==4){
                Renhaut(cube);printf("enHaut ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabR[0][0]==5){Renhaut(cube);printf("enHaut ");
            if(cube->tabBC[1][0]==1&&cube->tabO[0][1]==2){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasp ");
                RF(cube);printf("F ");
            }
            else if(cube->tabO[0][1]==3&&cube->tabBC[1][0]==2){
                RenhautP(cube);printf("enHautP ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabO[0][1]==4&&cube->tabBC[1][0]==3){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabO[0][1]==1&&cube->tabBC[1][0]==4){
                Renhaut(cube);printf("enHaut ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabO[0][0]==5){RenhautP(cube);printf("enHautP ");
            if(cube->tabBC[1][0]==1&&cube->tabO[0][1]==2){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabO[0][1]==3&&cube->tabBC[1][0]==2){
                RenhautP(cube);printf("enHautP ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabO[0][1]==4&&cube->tabBC[1][0]==3){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabO[0][1]==1&&cube->tabBC[1][0]==4){
                Renhaut(cube);printf("enHaut ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabB[0][0]==5){Renhaut(cube);Renhaut(cube);printf("enHaut enHaut ");
            if(cube->tabBC[1][0]==1&&cube->tabO[0][1]==2){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabO[0][1]==3&&cube->tabBC[1][0]==2){
                RenhautP(cube);printf("enHautP ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabO[0][1]==4&&cube->tabBC[1][0]==3){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabO[0][1]==1&&cube->tabBC[1][0]==4){
                Renhaut(cube);printf("enHaut ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        if(cube->tabV[0][1]==5){
            if(cube->tabBC[1][1]==3&&cube->tabR[0][0]==2){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabR[0][0]==3&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHAutP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabR[0][0]==4&&cube->tabBC[1][1]==1){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==2){
                Renhaut(cube);printf("enHaut ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabR[0][1]==5){Renhaut(cube);printf("enHaut ");
            if(cube->tabBC[1][1]==3&&cube->tabR[0][0]==2){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabR[0][0]==3&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHAutP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==2){
                Renhaut(cube);printf("enHaut ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabB[0][1]==5){Renhaut(cube);Renhaut(cube);printf("enHaut enHaut ");
            if(cube->tabBC[1][1]==3&&cube->tabR[0][0]==2){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabR[0][0]==3&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHAutP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==2){
                Renhaut(cube);printf("enHaut ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabO[0][1]==5){RenhautP(cube);printf("enHAutP ");
            if(cube->tabBC[1][1]==3&&cube->tabR[0][0]==2){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabR[0][0]==3&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHAutP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==4){
                RenhautP(cube);printf("enHautP ");
                RenhautP(cube);printf("enHautP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabR[0][0]==1&&cube->tabBC[1][1]==2){
                Renhaut(cube);printf("enHaut ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        if(cube->tabV[1][1]==5){
            if(cube->tabJ[0][1]==2&&cube->tabR[1][0]==3){
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][1]==3&&cube->tabR[1][0]==4){
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][1]==4&&cube->tabR[1][0]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabJ[0][1]==1&&cube->tabR[1][0]==2){
                RenbasP(cube);printf("enBasP ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabR[1][1]==5){RenbasP(cube);printf("enBasP ");
            if(cube->tabJ[0][1]==2&&cube->tabR[1][0]==3){
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][1]==3&&cube->tabR[1][0]==4){
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][1]==4&&cube->tabR[1][0]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabJ[0][1]==1&&cube->tabR[1][0]==2){
                RenbasP(cube);printf("enBasP ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabB[1][1]==5){RenbasP(cube);RenbasP(cube);printf("enBasP enBasP ");
            if(cube->tabJ[0][1]==2&&cube->tabR[1][0]==3){
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][1]==3&&cube->tabR[1][0]==4){
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][1]==4&&cube->tabR[1][0]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabJ[0][1]==1&&cube->tabR[1][0]==2){
                RenbasP(cube);printf("enBasP ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        else if(cube->tabO[1][1]==5){Renbas(cube);printf("enBas ");
            if(cube->tabJ[0][1]==2&&cube->tabR[1][0]==3){
                RenbasP(cube);printf("enBasP ");
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][1]==3&&cube->tabR[1][0]==4){
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][1]==4&&cube->tabR[1][0]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
            }
            else if(cube->tabJ[0][1]==1&&cube->tabR[1][0]==2){
                RenbasP(cube);printf("enBasP ");
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
            }
        }
        if(cube->tabV[1][0]==5){
            if(cube->tabJ[0][0]==2&&cube->tabO[1][1]==1){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabJ[0][0]==3&&cube->tabO[1][1]==2){
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][0]==4&&cube->tabO[1][1]==3){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][0]==1&&cube->tabO[1][1]==4){
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabR[1][0]==5){RenbasP(cube);printf("enBasP ");
            if(cube->tabJ[0][0]==2&&cube->tabO[1][1]==1){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabJ[0][0]==3&&cube->tabO[1][1]==2){
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][0]==4&&cube->tabO[1][1]==3){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][0]==1&&cube->tabO[1][1]==4){
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabB[1][0]==5){RenbasP(cube);RenbasP(cube);printf("enBasP enBasP ");
            if(cube->tabJ[0][0]==2&&cube->tabO[1][1]==1){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabJ[0][0]==3&&cube->tabO[1][1]==2){
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][0]==4&&cube->tabO[1][1]==3){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][0]==1&&cube->tabO[1][1]==4){
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        else if(cube->tabO[1][0]==5){Renbas(cube);printf("enBas ");
            if(cube->tabJ[0][0]==2&&cube->tabO[1][1]==1){
                RFP(cube);printf("FP ");
                RenbasP(cube);printf("enBasP ");
                RF(cube);printf("F ");
            }
            else if(cube->tabJ[0][0]==3&&cube->tabO[1][1]==2){
                Renbas(cube);printf("enBas ");
                RDP(cube);printf("DP ");
                RenbasP(cube);printf("enBasP ");
                RD(cube);printf("D ");
            }
            else if(cube->tabJ[0][0]==4&&cube->tabO[1][1]==3){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                RenbasP(cube);printf("enBasP ");
                RB(cube);printf("B ");
            }
            else if(cube->tabJ[0][0]==1&&cube->tabO[1][1]==4){
                RenbasP(cube);printf("enBasP ");
                RGP(cube);printf("GP ");
                RenbasP(cube);printf("enBasP ");
                RG(cube);printf("G ");
            }
        }
        if(cube->tabJ[0][1]==5){
            if(cube->tabR[1][0]==1&&cube->tabV[1][1]==2){
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==2&&cube->tabV[1][1]==3){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==3&&cube->tabV[1][1]==4){
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==4&&cube->tabV[1][1]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
        }
        else if(cube->tabJ[0][0]==5){Renbas(cube);printf("enBas ");
            if(cube->tabR[1][0]==1&&cube->tabV[1][1]==2){
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==2&&cube->tabV[1][1]==3){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==3&&cube->tabV[1][1]==4){
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==4&&cube->tabV[1][1]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
        }
        else if(cube->tabJ[1][0]==5){Renbas(cube);Renbas(cube);printf("enBas enBas ");
            if(cube->tabR[1][0]==1&&cube->tabV[1][1]==2){
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==2&&cube->tabV[1][1]==3){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==3&&cube->tabV[1][1]==4){
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==4&&cube->tabV[1][1]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
        }
        else if(cube->tabJ[1][1]==5){RenbasP(cube);printf("enBasP ");
            if(cube->tabR[1][0]==1&&cube->tabV[1][1]==2){
                RenbasP(cube);printf("enBasP ");
                RFP(cube);printf("FP ");
                Renbas(cube);printf("enBas ");
                RF(cube);printf("F ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==2&&cube->tabV[1][1]==3){
                RDP(cube);printf("DP ");
                Renbas(cube);printf("enBas ");
                RD(cube);printf("D ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==3&&cube->tabV[1][1]==4){
                Renbas(cube);printf("enBas ");
                RBP(cube);printf("BP ");
                Renbas(cube);printf("enBas ");
                RB(cube);printf("B ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
            else if(cube->tabR[1][0]==4&&cube->tabV[1][1]==1){
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
                RGP(cube);printf("GP ");
                Renbas(cube);printf("enBas ");
                RG(cube);printf("G ");
                Renbas(cube);printf("enBas ");
                Renbas(cube);printf("enBas ");
            }
        }
        if((cube->tabBC[0][0]==5&&cube->tabBC[0][1]==5&&cube->tabBC[1][0]==5&&cube->tabBC[1][1]==5)&&(cube->tabO[0][0]!=1||cube->tabO[0][1]!=1||cube->tabV[0][0]!=2||cube->tabV[0][1]!=2||cube->tabR[0][0]!=3||cube->tabR[0][1]!=3||cube->tabB[0][0]!=4||cube->tabB[0][1]!=4)){
            RG(cube);printf("G ");
            RD(cube);printf("D ");
        }
    }
    return cube;
}

CubeDeRubik *couronneInferieure(CubeDeRubik *cube)
{
    printf("\nLa couronne inferieure : ");

    while(cube->tabJ[0][1]!=6||cube->tabJ[0][0]!=6||cube->tabJ[1][0]!=6||cube->tabJ[1][1]!=6){
        /*if(cube->tabV[1][0]==1&&cube->tabV[1][1]==1){RenbasP(cube);printf("enBasP ");}
        else if(cube->tabR[1][0]==1&&cube->tabR[1][1]==1){RenbasP(cube);RenbasP(cube);printf("enBasP enBasP");}
        else if(cube->tabB[1][0]==1&&cube->tabB[1][1]==1){Renbas(cube);printf("enBas ");}
        if(cube->tabO[1][0]==2&&cube->tabO[1][1]==2){Renbas(cube);printf("enBas ");}
        else if(cube->tabR[1][0]==2&&cube->tabR[1][1]==2){RenbasP(cube);printf("enBasP");}
        else if(cube->tabB[1][0]==2&&cube->tabB[1][1]==2){Renbas(cube);Renbas(cube);printf("enBas enBas");}
        if(cube->tabO[1][0]==3&&cube->tabO[1][1]==3){Renbas(cube);Renbas(cube);printf("enBas enBas");}
        else if(cube->tabV[1][0]==3&&cube->tabV[1][1]==3){Renbas(cube);printf("enBas");}
        else if(cube->tabB[1][0]==3&&cube->tabB[1][1]==3){RenbasP(cube);printf("eenBasP");}
        if(cube->tabO[1][0]==4&&cube->tabO[1][1]==4){RenbasP(cube);printf("enBasP");}
        else if(cube->tabV[1][0]==4&&cube->tabV[1][1]==4){Renbas(cube);Renbas(cube);printf("enBas enBas");}
        else if(cube->tabR[1][0]==4&&cube->tabR[1][1]==4){Renbas(cube);printf("enBas");}
        if((cube->tabV[1][0]!=2||cube->tabV[1][1]!=2)&&(cube->tabB[1][0]==4&&cube->tabB[1][1]==4)){
            RDP(cube);printf("444DP ");
            Renbas(cube);printf("444enBas ");
            RD(cube);printf("444D ");
            Renbas(cube);printf("444enBas ");
            RF(cube);printf("444F ");
            RenbasP(cube);printf("444enBasP ");
            RFP(cube);printf("444FP ");
        }
        else if((cube->tabB[1][0]!=4||cube->tabB[1][1]!=4)&&(cube->tabV[1][0]==2&&cube->tabV[1][1]==2)){
            RGP(cube);printf("555GP ");
            Renbas(cube);printf("555enBas ");
            RG(cube);printf("555G ");
            Renbas(cube);printf("555enBas ");
            RB(cube);printf("555B ");
            RenbasP(cube);printf("555enBasP ");
            RBP(cube);printf("555BP ");
        }
        else if((cube->tabO[1][0]!=1||cube->tabO[1][1]!=1)&&(cube->tabR[1][0]==3&&cube->tabR[1][1]==3)){
            RFP(cube);printf("111FP ");
            Renbas(cube);printf("111enBas ");
            RF(cube);printf("111F ");
            Renbas(cube);printf("111enBas ");
            RG(cube);printf("111G ");
            RenbasP(cube);printf("111enBasP ");
            RGP(cube);printf("111GP ");
        }
        else if((cube->tabR[1][0]!=3||cube->tabR[1][1]!=3)&&(cube->tabO[1][0]==1&&cube->tabO[1][1]==1)){
            RBP(cube);printf("222BP ");
            Renbas(cube);printf("222enBas ");
            RB(cube);printf("222B ");
            Renbas(cube);printf("222enBas ");
            RD(cube);printf("222D ");
            RenbasP(cube);printf("222enBasP ");
            RDP(cube);printf("222DP ");
        }
        else {
            RDP(cube);printf("333DP ");
            Renbas(cube);printf("333enBas ");
            RD(cube);printf("333D ");
            Renbas(cube);printf("333enBas ");
            RF(cube);printf("333F ");
            RenbasP(cube);printf("333enBasP ");
            RFP(cube);printf("333FP ");
            RenbasP(cube);printf("333enBasP ");
            RBP(cube);printf("333BP ");
            Renbas(cube);printf("333enBas ");
            RB(cube);printf("333B ");
            Renbas(cube);printf("333enBas ");
            RD(cube);printf("333D ");
            RenbasP(cube);printf("333enBasP ");
            RDP(cube);printf("333DP ");
            Renbas(cube);printf("333enBas ");
        }*/
        if(cube->tabJ[1][0]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][1]!=6&&cube->tabJ[0][1]!=6){
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
            Renbas(cube);printf("enBas ");
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
        }
        if(cube->tabJ[1][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[0][1]!=6){
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabJ[0][0]==6&&cube->tabJ[1][1]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[0][1]!=6){
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabJ[0][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabO[1][0]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
            Renbas(cube);printf("enBas ");
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
        }
        if(cube->tabB[1][0]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabR[1][0]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabV[1][0]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            RenbasP(cube);printf("enbasP ");
        }
        if(cube->tabB[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
            Renbas(cube);printf("enBas ");
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
        }
        if(cube->tabO[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]==6){
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabV[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]==6){
            RenbasP(cube);printf("enBasP ");
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabR[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabB[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]==6){
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
            Renbas(cube);printf("enBas ");
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
        }
        if(cube->tabO[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]==6){
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabV[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]!=6){
            RenbasP(cube);printf("enBasP ");
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabR[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
        }
        if(cube->tabB[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]==6){
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
            Renbas(cube);printf("enBas ");
            RD(cube);printf("D ");
            Renbas(cube);printf("enBas ");
            Renbas(cube);printf("enBas ");
            RDP(cube);printf("DP ");
        }
        if(cube->tabO[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]!=6){
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabV[1][1]==6&&cube->tabJ[0][1]!=6&&cube->tabJ[0][0]==6&&cube->tabJ[1][0]!=6&&cube->tabJ[1][1]==6){
            RenbasP(cube);printf("enBasP ");
            RenbasP(cube);printf("enBasP ");
        }
        if(cube->tabR[1][1]==6&&cube->tabJ[0][1]==6&&cube->tabJ[0][0]!=6&&cube->tabJ[1][0]==6&&cube->tabJ[1][1]!=6){
            Renbas(cube);printf("enBas ");
        }
    }
    return cube;
}

CubeDeRubik *dernierecouronne(CubeDeRubik *cube)
{
    printf("\nLa derniere couronne : ");
    if(cube->tabV[1][0]==cube->tabV[1][1]&&cube->tabO[1][0]==cube->tabO[1][1]){
        while(cube->tabV[0][0]!=cube->tabV[1][0]){Renbas(cube);printf("enBas ");}
    }
    else{
        while(cube->tabV[1][0]!=2||cube->tabV[1][1]!=2||cube->tabO[1][0]!=1||cube->tabO[1][1]!=1||cube->tabB[1][0]!=4||cube->tabB[1][1]!=4||cube->tabR[1][0]!=3||cube->tabR[1][1]!=3)
        {
            if(cube->tabB[1][1]==cube->tabB[1][0])
            {
                if(cube->tabB[1][1]==3){
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabB[1][1]==2){
                    RenbasP(cube);printf("enBasP ");
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabB[1][1]==1){
                    Renbas(cube);printf("enBas ");
                }
            }
            else if(cube->tabR[1][1]==cube->tabR[1][0])
            {
                if(cube->tabR[1][1]==4){
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabR[1][1]==1){
                    RenbasP(cube);printf("enBasP ");
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabR[1][1]==2){
                    Renbas(cube);printf("enBas ");
                }
            }
            else if(cube->tabV[1][1]==cube->tabV[1][0])
            {
                if(cube->tabV[1][1]==1){
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabV[1][1]==4){
                    RenbasP(cube);printf("enBasP ");
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabV[1][1]==3){
                    Renbas(cube);printf("enBas ");
                }
            }
            else if(cube->tabO[1][1]==cube->tabO[1][0])
            {
                if(cube->tabO[1][1]==4){
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabO[1][1]==3){
                    RenbasP(cube);printf("enBasP ");
                    RenbasP(cube);printf("enBasP ");
                }
                else if(cube->tabO[1][1]==2){
                    Renbas(cube);printf("enBas ");
                }
            }
            if(cube->tabB[0][0]==4&&cube->tabB[0][1]==4&&cube->tabB[1][0]==4&&cube->tabB[1][1]==4){
                RGP(cube);printf("GP ");
                RF(cube);printf("F ");
                RGP(cube);printf("GP ");
                RB(cube);printf("B ");
                RB(cube);printf("B ");
                RG(cube);printf("G ");
                RFP(cube);printf("FP ");
                RGP(cube);printf("GP ");
                RB(cube);printf("B ");
                RB(cube);printf("B ");
                RG(cube);printf("G ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBasP ");
            }
            else if(cube->tabO[0][0]==1&&cube->tabO[0][1]==1&&cube->tabO[1][0]==1&&cube->tabO[1][1]==1){
                RFP(cube);printf("FP ");
                RD(cube);printf("D ");
                RFP(cube);printf("FP ");
                RG(cube);printf("G ");
                RG(cube);printf("G ");
                RF(cube);printf("F ");
                RDP(cube);printf("DP ");
                RFP(cube);printf("FP ");
                RG(cube);printf("G ");
                RG(cube);printf("G ");
                RF(cube);printf("F ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
            }
            else if(cube->tabV[0][0]==2&&cube->tabV[0][1]==2&&cube->tabV[1][0]==2&&cube->tabV[1][1]==2){
                RDP(cube);printf("DP ");
                RB(cube);printf("B ");
                RDP(cube);printf("DP ");
                RF(cube);printf("F ");
                RF(cube);printf("F ");
                RD(cube);printf("D ");
                RBP(cube);printf("BP ");
                RDP(cube);printf("DP ");
                RF(cube);printf("F ");
                RF(cube);printf("F ");
                RD(cube);printf("D ");
                RD(cube);printf("D ");
                RenbasP(cube);printf("enBas ");
            }
            else if(cube->tabR[0][0]==3&&cube->tabR[0][1]==3&&cube->tabR[1][0]==3&&cube->tabR[1][1]==3){
                RBP(cube);printf("BP ");
                RG(cube);printf("G ");
                RBP(cube);printf("BP ");
                RD(cube);printf("D ");
                RD(cube);printf("D");
                RB(cube);printf("B ");
                RGP(cube);printf("GP ");
                RBP(cube);printf("BP ");
                RD(cube);printf("D ");
                RD(cube);printf("D ");
                RB(cube);printf("B ");
                RB(cube);printf("B ");
                RenbasP(cube);printf("enBasP ");
            }
            if(cube->tabB[0][0]==4&&cube->tabB[0][1]==4&&cube->tabB[1][0]==4&&cube->tabB[1][1]==2){
                RGP(cube);printf("GP ");
                RF(cube);printf("F ");
                RGP(cube);printf("GP ");
                RB(cube);printf("B ");
                RB(cube);printf("B ");
                RG(cube);printf("G ");
                RFP(cube);printf("FP ");
                RGP(cube);printf("GP ");
                RB(cube);printf("B ");
                RB(cube);printf("B ");
                RG(cube);printf("G ");
                RG(cube);printf("G ");
                RenbasP(cube);printf("enBas ");
            }
            if(cube->tabO[0][0]==1&&cube->tabO[0][1]==1&&cube->tabO[1][0]==1&&cube->tabO[1][1]==3){
                RFP(cube);printf("FP ");
                RD(cube);printf("D ");
                RFP(cube);printf("FP ");
                RG(cube);printf("G ");
                RG(cube);printf("G");
                RF(cube);printf("F ");
                RDP(cube);printf("DP ");
                RFP(cube);printf("FP ");
                RG(cube);printf("G ");
                RG(cube);printf("G ");
                RF(cube);printf("F ");
                RF(cube);printf("F ");
                RenbasP(cube);printf("enBasP ");
            }
        }
    }
    return cube;
}

//fonction principale
int main(){

    CubeDeRubik cube;          //declaration du cube
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cube.tabO[i][j]=1;
            cube.tabV[i][j]=2;
            cube.tabR[i][j]=3;
            cube.tabB[i][j]=4;
            cube.tabBC[i][j]=5;
            cube.tabJ[i][j]=6;
        }
    }


    /*RD(&cube);                 //l'essai de quelques fonctions
    RG(&cube);
    Renhaut(&cube);
    Renbas(&cube);
    RF(&cube);
    RB(&cube);
    RDP(&cube);
    RGP(&cube);
    RenhautP(&cube);
    RenbasP(&cube);
    RFP(&cube);
    RBP(&cube);*/

    RANDOM(&cube);
    printf("\n");
    faceBlanche(&cube);
    printf("\n");
    couronneInferieure(&cube);
    printf("\n");
    dernierecouronne(&cube);
    printf("\n");
    affichagecube(&cube);      // l'affichage du cube
    return 0;                  //valeur de retour
}

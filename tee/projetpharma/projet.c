#include <stdio.h>
#include <gtk/gtk.h>


//void show_english_option(GtkWidget *widget , gpointer data);
void SetStyleCss(GtkWidget *widget , gchar *Name_class);
void PressButtonLang(GtkWidget *button , gpointer lang);
void switch_fenetre_display_1(GtkWidget *TsyAffichena , GtkWidget *Affichena);
void switch_fenetre_display_2(GtkWidget *TsyAffichena , GtkWidget *Affichena);
void lang_francais(GtkWidget *window);
void lang_Englais(GtkWidget *window);
void lang_Malagasy(GtkWidget *window);
void PressRetour(GtkWidget *button , gpointer data);
void ClickAdminFr(GtkWidget *buttonAdmin , gpointer data);


GtkWidget *win;
GtkWidget *winlang;


int main(int argc , char *argv[]){
     
    //initialisation
    gtk_init(&argc , &argv);

     //Fenetre 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   
    win = window; 
    //Style Css 
    SetStyleCss(window , "MyWindowMain");

    gtk_window_set_default_size(GTK_WINDOW(window) , 1000 , 600);
    //gtk_window_maximize(GTK_WINDOW(window));
    //gtk_window_set_resizable(GTK_WINDOW(window) , FALSE);

    gtk_window_set_title(GTK_WINDOW(window) , "PHARMAGEST"); 
    g_signal_connect(window , "destroy" , G_CALLBACK(gtk_main_quit) , NULL);
    
    //Conteneur principale
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 30);
    gtk_container_set_border_width(GTK_CONTAINER(box) , 30);
    gtk_container_add(GTK_CONTAINER(window) , box);
    
    //Creation de GRID
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid) , 30);
    gtk_grid_set_column_spacing(GTK_GRID(grid) , 30);
    gtk_container_add(GTK_CONTAINER(box) , grid);


    GtkWidget *buttonLogo = gtk_button_new();
    GtkWidget *logo = gtk_image_new_from_file("logo.svg");
    gtk_button_set_image(GTK_BUTTON(buttonLogo) , logo);
    gtk_grid_attach(GTK_GRID(grid) , buttonLogo, 0 , 0 , 1 , 1);
      SetStyleCss(buttonLogo , "buttonLogo");
    

    //Mise en place du texte
    GtkWidget *langue_text = gtk_image_new_from_file("langue.svg");
    gtk_grid_attach(GTK_GRID(grid) , langue_text , 1 , 3 , 5 , 1);
    
    /*
    GtkWidget *buttonVoice = gtk_button_new();
    buttonVoice = gtk_button_new_with_label("Click here to play sound");
    gtk_grid_attach(GTK_GRID(grid) , buttonVoice , 3 , 10 , 10 , 1);
    g_signal_connect(buttonVoice , "clicked" , G_CALLBACK(playSound) , NULL);
    */


    /*-----------------------------------FRANCAIS--------------------------------*/
    GtkWidget *buttonFr = gtk_button_new();
    buttonFr = gtk_button_new_with_label("FRANCAIS - FRENCH - FRANTSAY");
    gtk_grid_attach(GTK_GRID(grid) , buttonFr , 3 , 20 , 15 , 1);
    SetStyleCss(buttonFr , "buttonFr");
    g_signal_connect(buttonFr, "clicked" , G_CALLBACK(PressButtonLang) , NULL);

/*-----------------------------------ENGLISH--------------------------------*/
    GtkWidget *buttonEn = gtk_button_new();
    buttonEn = gtk_button_new_with_label("ENGLAIS - ENGLISH - ANGLISY");
    gtk_grid_attach(GTK_GRID(grid) , buttonEn , 3 , 25 , 15 , 1);
    SetStyleCss(buttonEn , "buttonEn");
    g_signal_connect(buttonEn , "clicked" , G_CALLBACK(PressButtonLang) , NULL);
    
    /*-----------------------------------MALAGASY--------------------------------*/
    GtkWidget *buttonMg = gtk_button_new();
    buttonMg = gtk_button_new_with_label("          MALAGASY          ");
    gtk_grid_attach(GTK_GRID(grid) , buttonMg , 3 , 30 , 15 , 1);
    SetStyleCss(buttonMg , "buttonMg");
    g_signal_connect(buttonMg , "clicked" , G_CALLBACK(PressButtonLang) , NULL);
    
    gtk_widget_show_all(window);
    
    system("mpg123 Bienvenue.mp3 &");   
    
    gtk_main();



    /*
    //Micreer bar de menu

    GtkWidget *menubar = gtk_menu_bar_new();

    //Menu 
    GtkWidget *MenuFichier = gtk_menu_new();

    //Creation du premier option du MenuFichier 
    GtkWidget *file1 = gtk_menu_item_new_with_label("LANGUE");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file1) , MenuFichier);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar) , file1);

    //Creation des options dans 1 
        //Creation de l' option langue anglais
        GtkWidget *OptionEnglish = gtk_menu_item_new_with_label("ENGLISH");
        gtk_menu_shell_append(GTK_MENU_SHELL(MenuFichier) , OptionEnglish);
        g_signal_connect(OptionEnglish , "activate" , G_CALLBACK(show_english_option) , NULL);
        
        //Creation de l'option francais
        GtkWidget *OptionFrancais = gtk_menu_item_new_with_label("FRANCAIS");
        gtk_menu_shell_append(GTK_MENU_SHELL(MenuFichier) , OptionFrancais);
        g_signal_connect(OptionFrancais , "activate" , G_CALLBACK(show_english_option) , NULL);
        
        //Creation de l'option malagasy
        GtkWidget *OptionMalagasy = gtk_menu_item_new_with_label("MALAGASY");
        gtk_menu_shell_append(GTK_MENU_SHELL(MenuFichier) , OptionMalagasy);
        g_signal_connect(OptionMalagasy , "activate" , G_CALLBACK(show_english_option) , NULL);

    //Creation du second option du MenuFichier
    GtkWidget *file2 = gtk_menu_item_new_with_label("");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file2) , MenuFichier);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar) , file2);

       

    gtk_grid_attach(GTK_GRID(grid) , menubar , 3 , 5 , 30 , 1);
    */

    //Lancer

    

    return 0;
}

void lang_Malagasy(GtkWidget *WindowMain){
   //Mamorona fenetre ho any francais 
    GtkWidget *windowMg = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    winlang = windowMg;
    //Omena classe style 
    SetStyleCss(windowMg , "MyWindowMg");

    //gtk_window_maximize(GTK_WINDOW(windowMg));
     gtk_window_set_default_size(GTK_WINDOW(windowMg) , 600 , 600);
    //gtk_window_set_resizable(GTK_WINDOW(windowMg) , FALSE);

    gtk_window_set_title(GTK_WINDOW(windowMg) , "PHARMAGEST");
    g_signal_connect(windowMg , "destroy" , G_CALLBACK(gtk_main_quit) , NULL);

    //Conteneur principale
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL , 550);
    gtk_container_set_border_width(GTK_CONTAINER(box) , 10);
    gtk_container_add(GTK_CONTAINER(windowMg) , box);

    //Creation de GRID
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid) , 30);
    gtk_grid_set_column_spacing(GTK_GRID(grid) , 100);
    gtk_container_add(GTK_CONTAINER(box) , grid);

    //Bouton de retour
    GtkWidget *buttonRetourMg = gtk_button_new();
    buttonRetourMg = gtk_button_new_with_label(" HIVERINA ");
    gtk_grid_attach(GTK_GRID(grid) , buttonRetourMg  , 10 , 1 , 1 , 1);
    SetStyleCss(buttonRetourMg  , "buttonRetour");
    g_signal_connect(buttonRetourMg , "clicked" , G_CALLBACK(PressRetour) , NULL);
    
    //Mise en place du drag
    GtkWidget *logoMg = gtk_image_new_from_file("mg.png");
    gtk_grid_attach(GTK_GRID(grid) , logoMg , 1 , 1 , 1 , 1);


    //Tsy affichena ny windowMain de affichena ny window FR
    switch_fenetre_display_1(WindowMain , windowMg);
    gtk_main();

    
}
void ClickAdminFr(GtkWidget *buttonAdmin , gpointer data){
    GtkWidget *WindowLogin = gtk_window_new(GTK_WINDOW_POPUP);

    gtk_window_set_default_size(GTK_WINDOW(WindowLogin) , 300 , 300);
    gtk_window_set_resizable(GTK_WINDOW(WindowLogin) , FALSE);
    SetStyleCss(WindowLogin , "MyWindowLogin");
    
    //Conteneur principale
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 20);
    gtk_container_set_border_width(GTK_CONTAINER(box) , 20);
    gtk_container_add(GTK_CONTAINER(WindowLogin) , box);
    

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid) , 20);
    gtk_grid_set_column_spacing(GTK_GRID(grid) , 20);
    gtk_container_add(GTK_CONTAINER(box) , grid);
    
    GtkWidget *entry = gtk_entry_new();
    //gtk_entry_set_text(GTK_ENTRY(entry) , "Entrer votre identifiant ici");

    gtk_grid_attach(GTK_GRID(grid) , entry , 10 , 10 , 1 , 1);


    switch_fenetre_display_1(winlang , WindowLogin);
    gtk_main();
}
void lang_francais(GtkWidget *WindowMain){
    //Mamorona fenetre ho any francais 
    GtkWidget *windowFr = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    winlang = windowFr;
    //Omena classe style 
    SetStyleCss(windowFr , "MyWindowFr");

    //gtk_window_maximize(GTK_WINDOW(windowFr));
     gtk_window_set_default_size(GTK_WINDOW(windowFr) , 600 , 600);
    //gtk_window_set_resizable(GTK_WINDOW(windowFr) , FALSE);

    gtk_window_set_title(GTK_WINDOW(windowFr) , "PHARMAGEST");
    g_signal_connect(windowFr , "destroy" , G_CALLBACK(gtk_main_quit) , NULL);


    //Conteneur principale
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 50);
    gtk_container_set_border_width(GTK_CONTAINER(box) , 10);
    gtk_container_add(GTK_CONTAINER(windowFr) , box);
    
    //Creation de GRID
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid) , 20);
    gtk_grid_set_column_spacing(GTK_GRID(grid) , 100);
    gtk_container_add(GTK_CONTAINER(box) , grid);
    
    GtkWidget *buttonRetourFr = gtk_button_new();
    buttonRetourFr = gtk_button_new_with_label(" RETOUR ");
    gtk_grid_attach(GTK_GRID(grid) , buttonRetourFr , 10 , 1 , 1 , 1);
    SetStyleCss(buttonRetourFr  , "buttonRetour");
    g_signal_connect(buttonRetourFr , "clicked" , G_CALLBACK(PressRetour) , NULL);

     //Mise en place du drag
    GtkWidget *logoFr = gtk_image_new_from_file("fr.png");
    gtk_grid_attach(GTK_GRID(grid) , logoFr , 1 , 1 , 1 , 1);

/*-----------------------------------ADMIN--------------------------------*/
    GtkWidget *buttonAdmin = gtk_button_new();
    buttonAdmin = gtk_button_new_with_label("ADMINISTRER");
    gtk_grid_attach(GTK_GRID(grid) , buttonAdmin , 3 , 6 , 4 , 1);
    g_signal_connect(buttonAdmin , "clicked" , G_CALLBACK(ClickAdminFr) , NULL);    
    SetStyleCss(buttonAdmin , "buttonAdmin");
    //g_signal_connect(buttonAdmin, "clicked" , G_CALLBACK(PressButtonLang) , NULL);

/*-----------------------------------ACHATS--------------------------------*/
    GtkWidget *buttonCli = gtk_button_new();
    buttonCli = gtk_button_new_with_label("ACHAT DU CLIENT");
    gtk_grid_attach(GTK_GRID(grid) , buttonCli , 3 , 15 , 4 , 1);
    SetStyleCss(buttonCli , "buttonCli");
    //g_signal_connect(buttonEn , "clicked" , G_CALLBACK(PressButtonLang) , NULL);
    
//Tsy affichena ny windowMain de affichena ny window FR
    switch_fenetre_display_1(WindowMain , windowFr);
    
    gtk_main();

}
void lang_Englais(GtkWidget *WindowMain){
    //Mamorona fenetre ho any francais 
    GtkWidget *windowEn = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    winlang = windowEn;
    //Omena classe style 
    SetStyleCss(windowEn , "MyWindowEn");

    //gtk_window_maximize(GTK_WINDOW(windowEn));
    gtk_window_set_default_size(GTK_WINDOW(windowEn) , 600 , 600);
    //gtk_window_set_resizable(GTK_WINDOW(windowEn) , FALSE);
    
    gtk_window_set_title(GTK_WINDOW(windowEn) , "PHARMAGEST");
    g_signal_connect(windowEn , "destroy" , G_CALLBACK(gtk_main_quit) , NULL);


    //Conteneur principale
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 50);
    gtk_container_set_border_width(GTK_CONTAINER(box) , 10);
    gtk_container_add(GTK_CONTAINER(windowEn) , box);
    
    //Creation de GRID
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid) , 20);
    gtk_grid_set_column_spacing(GTK_GRID(grid) , 100);
    gtk_container_add(GTK_CONTAINER(box) , grid);

    //Bouton de retour
    GtkWidget *buttonRetourEn = gtk_button_new();
    buttonRetourEn = gtk_button_new_with_label(" PREVIOUS ");
    gtk_grid_attach(GTK_GRID(grid) , buttonRetourEn ,  10 , 1 , 1 , 1);
    SetStyleCss(buttonRetourEn  , "buttonRetour");
    g_signal_connect(buttonRetourEn , "clicked" , G_CALLBACK(PressRetour) , NULL);

     //Mise en place du drag
    GtkWidget *logoEn = gtk_image_new_from_file("en.png");
    gtk_grid_attach(GTK_GRID(grid) , logoEn , 1 , 1 , 1 , 1);

  
    //Tsy affichena ny window1Main de affichena ny window FR
    switch_fenetre_display_1(WindowMain , windowEn);
    

    gtk_main();

}
void PressRetour(GtkWidget *button , gpointer data){
    switch_fenetre_display_2(winlang , win);

   // const gchar *label = gtk_button_get_label(GTK_BUTTON(button));

}

void switch_fenetre_display_1(GtkWidget *TsyAffichena , GtkWidget *Affichena){
    //Ho cachena ilay efa miseho
    gtk_widget_hide(TsyAffichena);
    
    //Affichena ilay vavao
    gtk_widget_show_all(Affichena);
 
}

void switch_fenetre_display_2(GtkWidget *TsyAffichena , GtkWidget *Affichena){
    //Ho cachena ilay efa miseho
    gtk_widget_destroy(TsyAffichena);
    
    //Affichena ilay vavao
    gtk_widget_show_all(Affichena);
}



void PressButtonLang(GtkWidget *button , gpointer lang){
   
    int choixlang = 0;
    
    const gchar *label = gtk_button_get_label(GTK_BUTTON(button));
    
    if(g_strcmp0(label , "FRANCAIS - FRENCH - FRANTSAY") == 0){
        choixlang = 1;
    } 
    else if(g_strcmp0(label , "ENGLAIS - ENGLISH - ANGLISY") == 0){
        choixlang = 2;
    }
    else{
        choixlang = 3;
    }


    if(choixlang == 1){
        lang_francais(win);
    } 
    else if(choixlang == 2){
        lang_Englais(win);
    }
    else{
        lang_Malagasy(win);
    }
}



void SetStyleCss(GtkWidget *widget , gchar *Name_class){
    GtkStyleContext *style_context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_class(style_context , Name_class);

    //Charge feuille de style CSS
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_file(css_provider , g_file_new_for_path("style.css") , NULL);
    gtk_style_context_add_provider(style_context , GTK_STYLE_PROVIDER(css_provider) , GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

/*
void show_english_option(GtkWidget *widget , gpointer data){
    //CREER UN BOITE DE DIALOGUE
    GtkWidget *dialog = gtk_message_dialog_new(NULL , GTK_DIALOG_MODAL , GTK_MESSAGE_INFO , GTK_BUTTONS_OK , "HELLO");

    //AFFICHER LA BOITE DE DIALOGUE ET ATTENDRE LA REPONSE DE L'USER
    gtk_dialog_run(GTK_DIALOG(dialog));

    //FERMER LA BOITE DE DIALOGUE 
    gtk_widget_destroy(dialog);
}
*/
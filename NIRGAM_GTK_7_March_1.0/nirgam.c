#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//******************************form4***********************************

int count2=0;
int r2=0;
char arr2[15][8];

char set[20] = "";

void form4()
{
  
char num[15];
char nam[15];
 
 if(count2==0)
 {
 FILE *input= fopen("application.config", "r+");

 while(feof(input)== 0)
{
 
 fscanf(input,"%s %s\n",num,nam);
 
  if(strcmp(nam,"Cbr.so")==0)
  {
 
  char sd[]="tile-";
  strcat(sd,num);
  strcpy(arr2[count2],sd);
  
    FILE *output= fopen(arr2[count2], "w+");
    
    fclose(output);
    count2++;
 }
}

 fclose(input);

}


//for the menu
  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *viewmenu;

  GtkWidget *file;
  GtkWidget *new;
  GtkWidget *open;
  GtkWidget *quit;
  GtkWidget *sep;

  //values
  char set_pkt_size[10];
  char set_load[10];
  char set_flit_interval[10];
  char set_destination[10];
  strcpy(set_pkt_size,"");
  strcpy(set_load,"");
  strcpy(set_flit_interval,"");
  strcpy(set_destination,"");
  
  //entry functions
  void entry0_selected(GtkWidget *widget, gpointer window)
{
 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
 strcpy(set_pkt_size,text);
   
  }
  void entry1_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_load,text);
   
  }
  void entry2_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_flit_interval,text);
   
  }
  void entry3_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_destination,text);
   
}
  
  
//menu


  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *next;

  GtkWidget *vbox;

//entries
  GtkWidget *entry0;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
 

//combos

  GtkWidget *combo_DESTINATION;
  
  
//labels
  
  GtkWidget *labelinfo;
  
  GtkWidget *label_title;

  GtkWidget *label0;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
 
  
  //gtk_init(&argc, &argv);

  vbox = gtk_vbox_new(FALSE, 3);
  // functions

   void combo_LOG_selected(GtkWidget *widget, gpointer label)
{ 
  
  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));

  strcpy(set,text);
  if(strcmp(set,"RANDOM")==0)
  {
   
  gtk_widget_hide_all(entry3);
  }
  if(strcmp(set,"FIXED")==0)
  {
    
  gtk_widget_show_all(entry3);
  }
   
}
  

//the menu

  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  viewmenu = gtk_menu_new();
	

  file = gtk_menu_item_new_with_mnemonic("_File");
  new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
  sep = gtk_separator_menu_item_new();
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
  
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  //the menu


  next = gtk_button_new_with_label("NEXT");
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "NIRGAM");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 550, 400);
  gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

  table = gtk_table_new(10,5, FALSE);
    
  //text entries
  entry0 = gtk_entry_new();
  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  
  gtk_entry_set_max_length (GTK_ENTRY(entry0),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry1),5);  
  gtk_entry_set_max_length (GTK_ENTRY(entry2),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry3),5);  
 
   
  gtk_entry_set_text (GTK_ENTRY(entry0), "");
  gtk_entry_set_text (GTK_ENTRY(entry1), "");
  gtk_entry_set_text (GTK_ENTRY(entry2), "");
  gtk_entry_set_text (GTK_ENTRY(entry3), "");

  
//combos with data


  combo_DESTINATION = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_DESTINATION), "FIXED");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_DESTINATION), "RANDOM");

  
  
//labels initialisation
    
  label0 = gtk_label_new("PKT_SIZE");
  label1 = gtk_label_new("LOAD");
  label2 = gtk_label_new("DESTINATION");
  label3 = gtk_label_new("FLIT-INTERVAL");
  
 
  //labels for combos

  label_title = gtk_label_new(arr2[r2]);
 
  labelinfo = gtk_label_new("--status--");
  //functions
  

  
void nextclicked(GtkWidget *widget, gpointer win2)
{

  FILE *p;
 
  p=fopen(arr2[r2],"w");
  fprintf(p,"PKT_SIZE %s\n",set_pkt_size); 
  fprintf(p,"LOAD %s\n",set_load);
  fprintf(p,"FLIT-INTERVAL %s\n",set_flit_interval);
  fprintf(p,"DESTINATION %s\n",set_destination);
  
  fclose(p);
  
    
  if(r2< (count2-1))
  {
  r2++;
  
  gtk_widget_hide_all(win2);
  gtk_main_quit();
  form4();
  }
  else
  {
  gtk_widget_hide_all(win2);
  gtk_main_quit();
  } 
  
}
//****************************table***********************************
//labels for combos

//labels for entries
 gtk_table_attach(GTK_TABLE(table), label0, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label1, 2, 3, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label3, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);



 gtk_table_attach(GTK_TABLE(table), labelinfo, 0, 2, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//combos


//WIDGETS
  gtk_table_attach(GTK_TABLE(table), entry0, 1, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_DESTINATION, 1, 2, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry1, 4, 5, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry2, 1, 2, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry3, 2, 3, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);



//buttons
gtk_table_attach(GTK_TABLE(table), next, 4, 5, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);


//SIGNALS

//**************combos signals******************************


 g_signal_connect(G_OBJECT(combo_DESTINATION), "changed", 
        G_CALLBACK(combo_LOG_selected), (gpointer) label3);

 g_signal_connect(G_OBJECT(next), "clicked", 
        G_CALLBACK(nextclicked), (gpointer) window);

//**************entry signals******************************

g_signal_connect(G_OBJECT(entry0), "changed", 
        G_CALLBACK(entry0_selected), (gpointer) label0);



g_signal_connect(G_OBJECT(entry1), "changed", 
        G_CALLBACK(entry1_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry2), "changed", 
        G_CALLBACK(entry2_selected), (gpointer) labelinfo);

  g_signal_connect(G_OBJECT(entry3), "changed", 
        G_CALLBACK(entry3_selected), (gpointer) labelinfo);


// arrangement
  
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(vbox), label_title, FALSE, FALSE, 3);

  gtk_box_pack_start(GTK_BOX(vbox), table, TRUE, TRUE, 3);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  
  
  //housekeeping!
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  //this is from the menu CTRl-Q
  g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  //gtk_widget_hide_all(window);  
  gtk_main();
 // fclose(p);
}


//******************************form4***********************************



//******************************form3***********************************

int count1=0;
int r=0;
char arr1[15][8];

void form3()
{
  
char num[15];
char nam[15];

 if(count1==0)
 {
 FILE *input= fopen("application.config", "r+");

 while(feof(input)== 0)
{
 
 fscanf(input,"%s %s\n",num,nam);
 
  if(strcmp(nam,"Bursty.so")==0)
  {
 
  char sd[]="tile-";
  strcat(sd,num);
  strcpy(arr1[count1],sd);
  
    FILE *output= fopen(arr1[count1], "w+");
    
    fclose(output);
    count1++;
 }
}

 fclose(input);

}

//for the menu
  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *viewmenu;

  GtkWidget *file;
  GtkWidget *new;
  GtkWidget *open;
  GtkWidget *quit;
  GtkWidget *sep;
  

  //values
  char set_pkt_size[10];
  char set_load[10];
  char set_flit_interval[10];
  char set_destination[10];
  strcpy(set_pkt_size,"");
  strcpy(set_load,"");
  strcpy(set_flit_interval,"");
  strcpy(set_destination,"");

  //entry functions
  void entry0_selected(GtkWidget *widget, gpointer window)
{

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_pkt_size,text);
   
  }
  void entry1_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_load,text);
   
  }
  void entry2_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_flit_interval,text);
   
  }
  void entry3_selected(GtkWidget *widget, gpointer window)
{

 gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_destination,text);
   
  }
  
  
//menu
  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *next;

  GtkWidget *vbox;

//entries
  GtkWidget *entry0;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
 
//combos

  GtkWidget *combo_DESTINATION;
  
//labels
  
  GtkWidget *labelinfo;
  
  GtkWidget *label_title;

  GtkWidget *label0;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
 

  //gtk_init(&argc, &argv);

  vbox = gtk_vbox_new(FALSE, 3);
  // functions
   void combo_LOG_selected(GtkWidget *widget, gpointer label)
{ 
  
  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));

  strcpy(set,text);
  if(strcmp(set,"RANDOM")==0)
  {
   
  gtk_widget_hide_all(entry3);
  }
  if(strcmp(set,"FIXED")==0)
  {
    
  gtk_widget_show_all(entry3);
  }
   
}
  

//the menu
  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  viewmenu = gtk_menu_new();
	
  
  file = gtk_menu_item_new_with_mnemonic("_File");
  new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
  sep = gtk_separator_menu_item_new();
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT,NULL);
  
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  //the menu


  next = gtk_button_new_with_label("NEXT");
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "NIRGAM");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 550, 400);
  gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

  table = gtk_table_new(10,5, FALSE);
    
  //text entries
  entry0 = gtk_entry_new();
  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  
  gtk_entry_set_max_length (GTK_ENTRY(entry0),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry1),5);  
  gtk_entry_set_max_length (GTK_ENTRY(entry2),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry3),5);  
 
   
  gtk_entry_set_text (GTK_ENTRY(entry0), "");
  gtk_entry_set_text (GTK_ENTRY(entry1), "");
  gtk_entry_set_text (GTK_ENTRY(entry2), "");
  gtk_entry_set_text (GTK_ENTRY(entry3), "");			

  
//combos with data


  combo_DESTINATION = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_DESTINATION), "FIXED");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_DESTINATION), "RANDOM");

  
  
//labels initialisation
    
  label0 = gtk_label_new("PKT_SIZE");
  label1 = gtk_label_new("LOAD");
  label2 = gtk_label_new("DESTINATION");
  label3 = gtk_label_new("FLIT-INTERVAL");
  
 
  //labels for combos

  label_title = gtk_label_new(arr1[r]);
 
  labelinfo = gtk_label_new("--status--");
  //functions
  

  
void nextclicked(GtkWidget *widget, gpointer win2)
{

  FILE *p;
  
  p=fopen(arr1[r],"w");
  fprintf(p,"PKT_SIZE %s\n",set_pkt_size); 
  fprintf(p,"LOAD %s\n",set_load);
  fprintf(p,"FLIT-INTERVAL %s\n",set_flit_interval);
  fprintf(p,"DESTINATION %s\n",set_destination);
  
  fclose(p);
  
    
  if(r< (count1-1))
  {
  r++;
  //fclose(q);
  gtk_widget_hide_all(win2);
  gtk_main_quit();
  form3();
  }
  else
  {
  gtk_widget_hide_all(win2);
  gtk_main_quit();
  } 

}

//****************************table***********************************
//labels for combos

//labels for entries
 gtk_table_attach(GTK_TABLE(table), label0, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label1, 2, 3, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label3, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);



 gtk_table_attach(GTK_TABLE(table), labelinfo, 0, 2, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//combos


//WIDGETS
  gtk_table_attach(GTK_TABLE(table), entry0, 1, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_DESTINATION, 1, 2, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry1, 4, 5, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry2, 1, 2, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry3, 2, 3, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);



//buttons
gtk_table_attach(GTK_TABLE(table), next, 4, 5, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);


//SIGNALS

//**************combos signals******************************


 g_signal_connect(G_OBJECT(combo_DESTINATION), "changed", 
        G_CALLBACK(combo_LOG_selected), (gpointer) label3);

 g_signal_connect(G_OBJECT(next), "clicked", 
        G_CALLBACK(nextclicked), (gpointer) window);

//**************entry signals******************************

g_signal_connect(G_OBJECT(entry0), "changed", 
        G_CALLBACK(entry0_selected), (gpointer) label0);



g_signal_connect(G_OBJECT(entry1), "changed", 
        G_CALLBACK(entry1_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry2), "changed", 
        G_CALLBACK(entry2_selected), (gpointer) labelinfo);

  g_signal_connect(G_OBJECT(entry3), "changed", 
        G_CALLBACK(entry3_selected), (gpointer) labelinfo);


// arrangement
  
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(vbox), label_title, FALSE, FALSE, 3);

  gtk_box_pack_start(GTK_BOX(vbox), table, TRUE, TRUE, 3);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  
  
  //housekeeping!
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  //this is from the menu CTRl-Q
  g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  //gtk_widget_hide_all(window);  
  gtk_main();
 // fclose(p);


}
 

//******************************form3***********************************




char set_topology[10] = "MESH",set_dirname[10]="res",set_rt_algo[10]="XY",set_num_rows[10]="5",set_num_cols[10]="5",set_num_bufs[10]="16",set_flitsize[10],set_head_payload[10],set_data_payload[10],set_log[10]="1",set_sim_num[10],set_warmup[10],set_tg_num[10],set_clk_freq[10];

int val0,val1,val2,val3,val4,val5,val6,val7;
val4 = 3000; //SIM_NUM
val5 = 5;    //WARMUP
val6 = 2500; //TG_NUM	

void combo_TOPOLOGY_selected(GtkWidget *widget, gpointer window)
{ 
   
  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_topology,text);
}


void combo_RT_ALGO_selected(GtkWidget *widget, gpointer window)
{ 
  
  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_rt_algo,text);
  
  }

void combo_NUM_ROWS_selected(GtkWidget *widget, gpointer window)
{

  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_num_rows,text);
   
  }

void combo_NUM_COLS_selected(GtkWidget *widget, gpointer window)
{

  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_num_cols,text);
   
  }

void combo_NUM_BUFS_selected(GtkWidget *widget, gpointer window)
{

  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_num_bufs,text);
  }

void combo_LOG_selected(GtkWidget *widget, gpointer window)
{ 

  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set_log,text);
  
  }

//callbacks for entries
void entry0_selected(GtkWidget *widget, gpointer window)
{ 

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_flitsize,text);
  val0 = atoi(set_flitsize);


   
  }

void entry1_selected(GtkWidget *widget, gpointer label)
{
  

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_head_payload,text);
  val1 = atoi(set_head_payload);  

  if (val1 > val0){
  gtk_entry_set_text(widget,"");
  gtk_label_set_text(label,"HEAD_PAYLOAD < FLITSIZE!");
   }

}

void entry2_selected(GtkWidget *widget, gpointer label)
{ 

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_data_payload,text);
  val2 = atoi(set_data_payload);
  
  if (val2 > val0){
  gtk_entry_set_text(widget,"");  
  gtk_label_set_text(label,"DATA_PAYLOAD < FLITSIZE!");
  }
}

void entry3_selected(GtkWidget *widget, gpointer window)
{ 

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_dirname,text);
  
  
}

void entry4_selected(GtkWidget *widget, gpointer window)
{

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_sim_num,text);
  val4 = atoi(set_sim_num);
  }

void entry5_selected(GtkWidget *widget, gpointer label)
{

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_warmup,text);
  val5 = atoi(set_warmup);

  if (val5 > val4){
  gtk_entry_set_text(widget,"");
  gtk_label_set_text(label,"WARMUP < SIM_NUM!");
   }

  }

void entry6_selected(GtkWidget *widget, gpointer label)
{

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_tg_num,text);
  val6 = atoi(set_tg_num);  

  //if (val6 > val4) {
  //gtk_entry_set_text(widget,"");  
  gtk_label_set_text(label,"WARMUP<TG_NUM<SIMNUM!");
  //}
  
    
}

void entry7_selected(GtkWidget *widget, gpointer window)
{

  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(set_clk_freq,text);
  val7 = atoi(set_clk_freq);
  
}


//*********************************form2********************************


void form2(){

FILE *pq;
pq=fopen("application.config","w");
fclose(pq);

int count =1;
int tile = 0;
char set[20] = "App_send.so";
char data[20] = "App_send.so";
char buf[15];
char data2[10];

void combo2_selected(GtkWidget *widget, gpointer window)
{ 
  
  gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
  strcpy(set,text);
   
}

void entry_combo_selected(GtkWidget *widget, gpointer label)
{
 // char data[10];
  gchar *text = gtk_entry_get_text(GTK_ENTRY (widget));
  strcpy(data2,text);
  
  tile = atoi(data2);
}

void next2clicked(GtkWidget *widget, gpointer win2)
{
	
  char num[15];
  char nam[15];
  int bflag =0;
  int cflag =0;
   
  
 gtk_widget_hide_all(win2);
 gtk_main_quit();

  FILE *q;
  q=fopen("application.config","r+");

 while(feof(q)== 0)
{
 
 fscanf(q,"%s %s\n",num,nam);
 
  if(strcmp(nam,"Bursty.so")==0)
  {
   bflag =1;
  }
  else if(strcmp(nam,"Cbr.so")==0)
  {
   cflag =1;
  }
  else ;
}

fclose(q);

if((bflag==1) && (cflag==1))
	{
	form3();
	form4();
	}

else if(bflag){
  form3();
}

else if (cflag){
  form4();
}

else  
  gtk_main_quit();
  
}


void addclicked(GtkWidget *widget, gpointer label)
{
FILE *q;
q=fopen("application.config","a");
if(set=="")
strcpy(set,data);
  
  fprintf(q,"%d %s\n",tile, set); 
  sprintf(buf, " Entry added: %d", count);  
  gtk_label_set_text(label, buf);
  count ++;
fclose(q);

}

void resetclicked(GtkWidget *widget, gpointer label)
{
FILE *pq;
pq=fopen("application.config","w");
sprintf(buf, " RESET: Entries deleted: %d", count);  
gtk_label_set_text(label, buf);
count =1;
fclose(pq);
}

void backclicked(GtkWidget *widget, gpointer win2)
{

gtk_widget_hide_all(win2);
gtk_main_quit();
form1();

}


  GtkWidget *window2;

  GtkWidget *table2;

  GtkWidget *next2;
  GtkWidget *reset;
  GtkWidget *add;
  GtkWidget *back;


  GtkWidget *vbox2;

//entries

  GtkWidget *entry_combo;
 
//combos
  GtkWidget *combo2;
  
//labels
  
  
  GtkWidget *label_entry_count;
  GtkWidget *label_title2;
  GtkWidget *label_info;
    
// gtk_init(&argc, &argv);

  vbox2 = gtk_vbox_new(FALSE, 10);
  
  next2 = gtk_button_new_with_label("NEXT");
  add = gtk_button_new_with_label("ADD");
   reset = gtk_button_new_with_label("RESET");
  back = gtk_button_new_with_label("BACK");
  
  window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window2), "NIRGAM");
  gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window2), 550, 400);
  gtk_window_set_resizable (GTK_WINDOW(window2), FALSE);

  table2 = gtk_table_new(6,5, FALSE);
    
  //text entries
  
  entry_combo = gtk_entry_new();
  gtk_entry_set_text (GTK_ENTRY(entry_combo), "0");  
  gtk_entry_set_max_length (GTK_ENTRY(entry_combo),5);  
   
    
//combos with data
  combo2 = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "App_send.so");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "App_concat.so");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "App_recv.so");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "Bursty.so");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "Cbr.so");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo2), "Sink.so");
  

  
//labels initialisation
    
   
  label_entry_count = gtk_label_new("TILE NO:");
  
  label_title2 = gtk_label_new("application.config");
 
  label_info = gtk_label_new("---status----");
  

//****************************table***********************************
//labels
 
gtk_table_attach(GTK_TABLE(table2), label_entry_count, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

gtk_table_attach(GTK_TABLE(table2), label_info, 0, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//combos
  gtk_table_attach(GTK_TABLE(table2), combo2, 3, 5, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//text entries
  gtk_table_attach(GTK_TABLE(table2), entry_combo, 1, 2, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//buttons
gtk_table_attach(GTK_TABLE(table2), next2, 3, 5, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

gtk_table_attach(GTK_TABLE(table2), reset, 3, 5, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

gtk_table_attach(GTK_TABLE(table2), add, 1, 2, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

gtk_table_attach(GTK_TABLE(table2), back, 0, 1, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
//SIGNALS

//**************combos siginals******************************
g_signal_connect(G_OBJECT(combo2), "changed", 
        G_CALLBACK(combo2_selected), (gpointer) entry_combo);

//**************button siginals******************************

 g_signal_connect(G_OBJECT(next2), "clicked", 
        G_CALLBACK(next2clicked), (gpointer) window2);
 
 g_signal_connect(G_OBJECT(reset), "clicked", 
        G_CALLBACK(resetclicked), (gpointer) label_info);

 g_signal_connect(G_OBJECT(add), "clicked", 
        G_CALLBACK(addclicked), (gpointer) label_info);

g_signal_connect(G_OBJECT(back), "clicked", 
        G_CALLBACK(backclicked), (gpointer) window2);
//**************entry siginals******************************

  g_signal_connect(G_OBJECT(entry_combo), "changed", 
        G_CALLBACK(entry_combo_selected), NULL);


// arrangement
  
  gtk_box_pack_start(GTK_BOX(vbox2), label_title2, FALSE, FALSE, 3);

  gtk_box_pack_start(GTK_BOX(vbox2), table2, TRUE, TRUE, 3);

  gtk_container_add(GTK_CONTAINER(window2), vbox2);
  
  
  //housekeeping!
  g_signal_connect_swapped(G_OBJECT(window2), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window2));


  gtk_widget_show_all(window2);
  
  gtk_main();
 

}


//*********************************form2********************************




//*********************************form1********************************
	
void form1(){

//for the menu
  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *viewmenu;

  GtkWidget *file;
  GtkWidget *new;
  GtkWidget *open;
  GtkWidget *quit;
  GtkWidget *sep;
//menu


  GtkWidget *window;
  GtkWidget *table;


  GtkWidget *next;

  GtkWidget *vbox;

//entries
  GtkWidget *entry0;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry5;
  GtkWidget *entry6;
  GtkWidget *entry7;

//combos
  GtkWidget *combo_TOPOLOGY;
  GtkWidget *combo_NUM_ROWS;
  GtkWidget *combo_NUM_COLS;
  GtkWidget *combo_RT_ALGO;
  GtkWidget *combo_NUM_BUFS;
  GtkWidget *combo_LOG;
  
  
//labels
  
  GtkWidget *labelinfo;
  
  GtkWidget *label_title;

  GtkWidget *label0;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *label6;
  GtkWidget *label7;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *label13;
  
  vbox = gtk_vbox_new(FALSE, 3);


void nextclicked(GtkWidget *widget, gpointer win)
{
    
  FILE *p;
  p=fopen("nirgam.config","w");
  fprintf(p,"TOPOLOGY %s\n",set_topology); 
  fprintf(p,"RT_ALGO %s\n",set_rt_algo);
  fprintf(p,"NUM_ROWS %s\n",set_num_rows);
  fprintf(p,"NUM_COLS %s\n",set_num_cols);
  fprintf(p,"NUM_BUFS %s\n",set_num_bufs); 
  fprintf(p,"LOG %s\n",set_log);
  
  if(val0 == 0)
  fprintf(p,"FLITSIZE \n");
  else
  fprintf(p,"FLITSIZE %d\n",val0);
  
  fprintf(p,"DIRNAME %s\n",set_dirname);
  
  if(val1 == 0)
  fprintf(p,"HEAD_PAYLOAD \n");
  else
  fprintf(p,"HEAD_PAYLOAD %d\n",val1);
  
  if(val2 == 0)
  fprintf(p,"DATA_PAYLOAD \n");
  else
  fprintf(p,"DATA_PAYLOAD %d\n",val2);

  fprintf(p,"SIM_NUM %d\n",val4);
  fprintf(p,"WARMUP %d\n",val5);
  fprintf(p,"TG_NUM %d\n",val6);

  if(val7 == 0)
  fprintf(p,"CLK_FREQ \n");
  else
  fprintf(p,"CLK_FREQ %d\n",val7);


  fclose(p);
  
  gtk_widget_hide_all(win);
  
  form2();
  /*this causes  Gtk-CRITICAL **: gtk_main_quit:
    assertion `main_loops != NULL' failed -- quits completely
  */
  gtk_main_quit();

   
}

//the menu

  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  viewmenu = gtk_menu_new();
	
  file = gtk_menu_item_new_with_mnemonic("_File");
  new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
  sep = gtk_separator_menu_item_new();
  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
  

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  //the menu


  next = gtk_button_new_with_label("NEXT");
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "NIRGAM");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 550, 400);
  gtk_window_set_resizable (GTK_WINDOW(window), FALSE);

  table = gtk_table_new(10,5, FALSE);
    
  //text entries
  entry0 = gtk_entry_new();
  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  entry4 = gtk_entry_new();
  entry5 = gtk_entry_new();
  entry6 = gtk_entry_new();
  entry7 = gtk_entry_new();
  
  gtk_entry_set_max_length (GTK_ENTRY(entry0),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry1),5);  
  gtk_entry_set_max_length (GTK_ENTRY(entry2),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry3),5);  
  gtk_entry_set_max_length (GTK_ENTRY(entry4),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry5),5);  
  gtk_entry_set_max_length (GTK_ENTRY(entry6),5);
  gtk_entry_set_max_length (GTK_ENTRY(entry7),5);  
   
  gtk_entry_set_text (GTK_ENTRY(entry0), "");
  gtk_entry_set_text (GTK_ENTRY(entry1), "");
  gtk_entry_set_text (GTK_ENTRY(entry2), "");
  gtk_entry_set_text (GTK_ENTRY(entry3), "res");
  gtk_entry_set_text (GTK_ENTRY(entry4), "3000");
  gtk_entry_set_text (GTK_ENTRY(entry5), "5");
  gtk_entry_set_text (GTK_ENTRY(entry6), "2500");
  gtk_entry_set_text (GTK_ENTRY(entry7), "");
  
//combos with data
  combo_TOPOLOGY = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_TOPOLOGY), "MESH");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_TOPOLOGY), "TORUS");
    

  combo_NUM_ROWS = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "1");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "2");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "3");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "4");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "5");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "6");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "7");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "8");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_ROWS), "9");

  combo_NUM_COLS = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "1");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "2");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "3");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "4");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "5");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "6");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "7");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "8");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_COLS), "9");


  combo_RT_ALGO = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "XY");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "OE");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "SOURCE");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "DYAD");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "QRT");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "MAXY");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "FTXY");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_RT_ALGO), "PROM");

  combo_NUM_BUFS = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "1");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "2");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "3");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "4");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "5");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "6");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "7");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "8");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "9");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "10");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "11");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "12");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "13");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "14");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "15");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_NUM_BUFS), "16");

  combo_LOG = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_LOG), "0");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_LOG), "1");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_LOG), "2");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_LOG), "3");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo_LOG), "4");
  
  
//labels initialasation
    
  label0 = gtk_label_new("FLITSIZE");
  label1 = gtk_label_new("HEAD_PAYLOAD");
  label2 = gtk_label_new("DATA_PAYLOAD");
  label3 = gtk_label_new("DIRNAME");
  label4 = gtk_label_new("SIM_NUM");
  label5 = gtk_label_new("WARMUP");
  label6 = gtk_label_new("TG_NUM");
  label7 = gtk_label_new("CLK_FREQ");
  //labels for combos
  label8 = gtk_label_new("TOPOLOGY");
  label9 = gtk_label_new("NUM_ROWS");
  label10 = gtk_label_new("NUM_COLS");
  label11 = gtk_label_new("RT_ALGO");
  label12 = gtk_label_new("NUM_BUFS");
  label13 = gtk_label_new("LOG");


  label_title = gtk_label_new("nirgam.config");
 
  labelinfo = gtk_label_new("--status--");
  

//****************************table***********************************
//labels for combos
 gtk_table_attach(GTK_TABLE(table), label8, 0, 1, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label9, 0, 1, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label10, 0, 1, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label11, 3, 4, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label12, 3, 4, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label13, 3, 4, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
//labels for entries
 gtk_table_attach(GTK_TABLE(table), label0, 0, 1, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 5, 6, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 6, 7, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label3, 0, 1, 7, 8, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label4, 3, 4, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label5, 3, 4, 5, 6, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label6, 3, 4, 6, 7, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
 gtk_table_attach(GTK_TABLE(table), label7, 3, 4, 7, 8, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);


 gtk_table_attach(GTK_TABLE(table), labelinfo, 0, 2, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//combos
  gtk_table_attach(GTK_TABLE(table), combo_TOPOLOGY, 1, 2, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_NUM_ROWS, 1, 2, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_NUM_COLS, 1, 2, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_RT_ALGO, 4, 5, 0, 1, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_NUM_BUFS, 4, 5, 1, 2, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), combo_LOG, 4, 5, 2, 3, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//text entries
  gtk_table_attach(GTK_TABLE(table), entry0, 1, 2, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry1, 1, 2, 5, 6, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry2, 1, 2, 6, 7, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry3, 1, 2, 7, 8, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry4, 4, 5, 4, 5, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry5, 4, 5, 5, 6, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry6, 4, 5, 6, 7, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry7, 4, 5, 7, 8, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

//buttons
gtk_table_attach(GTK_TABLE(table), next, 4, 5, 9, 10, 
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);


//SIGNALS

//**************combos siginals******************************
g_signal_connect(G_OBJECT(combo_TOPOLOGY), "changed", 
        G_CALLBACK(combo_TOPOLOGY_selected), (gpointer) label0);

g_signal_connect(G_OBJECT(combo_NUM_ROWS), "changed", 
        G_CALLBACK(combo_NUM_ROWS_selected), (gpointer) label1);

g_signal_connect(G_OBJECT(combo_NUM_COLS), "changed", 
        G_CALLBACK(combo_NUM_COLS_selected), (gpointer) label2);

g_signal_connect(G_OBJECT(combo_RT_ALGO), "changed", 
        G_CALLBACK(combo_RT_ALGO_selected), (gpointer) label3);

 g_signal_connect(G_OBJECT(combo_NUM_BUFS), "changed", 
        G_CALLBACK(combo_NUM_BUFS_selected), (gpointer) label4);

 g_signal_connect(G_OBJECT(combo_LOG), "changed", 
        G_CALLBACK(combo_LOG_selected), (gpointer) label5);

 g_signal_connect(G_OBJECT(next), "clicked", 
        G_CALLBACK(nextclicked), (gpointer) window);

//**************entry siginals******************************

g_signal_connect(G_OBJECT(entry0), "changed", 
        G_CALLBACK(entry0_selected), (gpointer) label0);

g_signal_connect(G_OBJECT(entry1), "changed", 
        G_CALLBACK(entry1_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry2), "changed", 
        G_CALLBACK(entry2_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry3), "changed", 
        G_CALLBACK(entry3_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry4), "changed", 
        G_CALLBACK(entry4_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry5), "changed", 
        G_CALLBACK(entry5_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry6), "changed", 
        G_CALLBACK(entry6_selected), (gpointer) labelinfo);

g_signal_connect(G_OBJECT(entry7), "changed", 
        G_CALLBACK(entry7_selected), (gpointer) labelinfo);



// arrangement
  
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(vbox), label_title, FALSE, FALSE, 3);

  gtk_box_pack_start(GTK_BOX(vbox), table, TRUE, TRUE, 3);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  
  
  //housekeeping!
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  //this is from the menu CTRl-Q
  g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  //gtk_widget_hide_all(window);  
  gtk_main();



}

//*********************************form1********************************

	


//********************************main***********************************

int main(int argc, char *argv[])
{

 gtk_init(&argc, &argv);
 form1();

 //gtk_main_quit();
 return 0;
}

//********************************main**********************************

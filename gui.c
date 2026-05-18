#include"globals.h"
#include"gtk/gtk.h"
#include"guii.h"
#include "game.h"
// Function to open the About window
void open_about_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *fixed;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "About");
    gtk_window_set_default_size(GTK_WINDOW(window), 580, 680); // Adjust size as needed
    gtk_window_move(GTK_WINDOW(window), 700, 300);

    // Create a fixed container
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Load the image
    image = gtk_image_new_from_file("C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\Chessrules1.png");
    gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);
    gtk_widget_show_all(window);
}// Function to exit the application
void exit_application(GtkWidget *widget, gpointer data) {
    if (mode_window != NULL) {
        gtk_widget_destroy(mode_window);
    }
    GtkWidget *window = (GtkWidget *)data;
    gtk_widget_destroy(window);
    gtk_main_quit();
}
// Function to open the Mode window
void open_mode_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *button_pvp;
    GtkWidget *button_ai;
    //GtkWidget *button_exit;
    GtkWidget *label;
    GtkWidget *image;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Mode");
    gtk_window_set_default_size(GTK_WINDOW(window), 580, 180);
    gtk_window_move(GTK_WINDOW(window), 700, 250);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Create a woodish background
    GdkRGBA woodish_color;
    gdk_rgba_parse(&woodish_color, "#4682B4"); // SaddleBrown color for woodish effect
    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, &woodish_color);

    // Create the label at the center top
    label = gtk_label_new("MODE");
    PangoFontDescription *font_desc = pango_font_description_from_string("Sans Bold 44");
    gtk_widget_override_font(label, font_desc);
    pango_font_description_free(font_desc);
    gtk_fixed_put(GTK_FIXED(fixed), label, 195, 10);
    gtk_widget_set_name(label, "glow_label");

    // Create glowing big buttons
    button_pvp = gtk_button_new_with_label("PvP");
    gtk_widget_set_size_request(button_pvp, 150, 50);
    g_signal_connect(button_pvp, "clicked", G_CALLBACK(open_pvp_chessboard), app);
    gtk_fixed_put(GTK_FIXED(fixed), button_pvp, 110, 100);
    gtk_widget_set_name(button_pvp, "glow_button");

    button_ai = gtk_button_new_with_label("AI");
    gtk_widget_set_size_request(button_ai, 150, 50);
    g_signal_connect(button_ai, "clicked", G_CALLBACK(open_chessboard), app);
    gtk_fixed_put(GTK_FIXED(fixed), button_ai, 320, 100);
    gtk_widget_set_name(button_ai, "glow_button");

    gtk_widget_show_all(window);

    // Apply CSS styling
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "#glow_button {"
        "  background-color: #FFD700;" // Gold color for glowing effect
        "  border-radius: 10px;"
        "  border: 2px solid #FFD700;"
        "  box-shadow: 0px 0px 10px 2px #FFD700;"
        "  transition: box-shadow 0.3s ease-in-out;"
        "}"
        "#glow_button:hover {"
        "  box-shadow: 0px 0px 20px 5px #FFD700;"
        "}"
        "#glow_label {"
        "  color: #FFD700;" // Gold color for text
        "  text-shadow: 0px 0px 10px #FFD700;"
        "}",
        -1, NULL);

    GtkStyleContext *context_pvp = gtk_widget_get_style_context(button_pvp);
    gtk_style_context_add_provider(context_pvp, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    GtkStyleContext *context_ai = gtk_widget_get_style_context(button_ai);
    gtk_style_context_add_provider(context_ai, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //GtkStyleContext *context_exit = gtk_widget_get_style_context(button_exit);
    //gtk_style_context_add_provider(context_exit, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    GtkStyleContext *context_label = gtk_widget_get_style_context(label);
    gtk_style_context_add_provider(context_label, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    mode_window = window;
}
// Activation function for the initial window
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *button_exit;
    GtkWidget *button_about;
    GtkWidget *button_mode;
    GtkWidget *background_image;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "CHECKMATE");
    gtk_window_set_default_size(GTK_WINDOW(window), 580, 680); // Adjust size as needed
    gtk_window_move(GTK_WINDOW(window), 700, 100);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Load and add the background image
    char* image_path = "C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\chess2.png"; // Update the path to your image file
    background_image = gtk_image_new_from_file(image_path);
    gtk_fixed_put(GTK_FIXED(fixed), background_image, 0, 0);

    // Create About button
    button_about = gtk_button_new_with_label("HI ! NEED HELP ?");
    g_signal_connect(button_about, "clicked", G_CALLBACK(open_about_window), app);
    gtk_fixed_put(GTK_FIXED(fixed), button_about, 98, 1);
    gtk_widget_set_name(button_about, "ovaLl_button");

    // Create Exit button
    button_exit = gtk_button_new_with_label("Exit");
    g_signal_connect(button_exit, "clicked", G_CALLBACK(exit_application), window);
    gtk_fixed_put(GTK_FIXED(fixed), button_exit, 17, 620);
    gtk_widget_set_name(button_exit, "ovLal_button");

    // Create Mode button
    button_mode = gtk_button_new_with_label("PLAY");
    g_signal_connect(button_mode, "clicked", G_CALLBACK(open_mode_window), app);
    gtk_fixed_put(GTK_FIXED(fixed), button_mode, 483, 620);
    gtk_widget_set_name(button_mode, "oval_button");

    gtk_widget_show_all(window);
    // Apply CSS styling
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        
        "#oval_button {"
        "  background-color: #C50725;" // Gold color
        "  border-radius: 25px;" // Change to a high value to make the button oval
        "  padding: 8px 25px;" // Adjust padding to make the button more oval
        "}"
        "#ovLal_button {"
        "  background-color: #C50725;" // Gold color
        "  border-radius: 25px;" // Change to a high value to make the button oval
        "  padding: 8px 25px;" // Adjust padding to make the button more oval
        "}"
        "#ovaLl_button {"
        "  background-color: #FFD700;" // Gold color
        "  border-radius: 50px;" // Change to a high value to make the button oval
        "  padding: .0001px 142px;" // Adjust padding to make the button more oval
        "}"
        ,
        -1, NULL);

    GtkStyleContext *context_exit = gtk_widget_get_style_context(button_exit);
    gtk_style_context_add_provider(context_exit, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

   /* GtkStyleContext *context_about = gtk_widget_get_style_context(button_about);
    gtk_style_context_add_provider(context_about, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);*/

    GtkStyleContext *context_mode = gtk_widget_get_style_context(button_mode);
    gtk_style_context_add_provider(context_mode, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    GtkStyleContext *context_about_button = gtk_widget_get_style_context(button_about);
    gtk_style_context_add_provider(context_about_button, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // GtkStyleContext *context_about_label = gtk_widget_get_style_context(about_label);
    // gtk_style_context_add_provider(context_about_label, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void open_chessboard(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *background_area;
    // GtkWidget *grid;
    GtkWidget *drawing_area;
    GtkWidget *back_button;
    ButtonData *button_data;
     GtkWidget *background_image;

    int i, j;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "PvP Mode");
    gtk_window_set_default_size(GTK_WINDOW(window), 580, 680);
    gtk_window_move(GTK_WINDOW(window), 700, 100);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Load and add the background image
    char* image_path = "C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\chess3.png"; // Update the path to your image file
    background_image = gtk_image_new_from_file(image_path);
    gtk_fixed_put(GTK_FIXED(fixed), background_image, 0, 0);
   
    grid = gtk_grid_new();

    // Draw dark brown border around chessboard
    GtkWidget *border_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(border_area, 500, 500);
    g_signal_connect(border_area, "draw", G_CALLBACK(draw_border), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), border_area, 40, 40); // Position the border area around the grid

    // Create 64 drawing areas (8x8 grid)
    ButtonData *button_data_grid[8][8]; // To store button data for each grid cell
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            drawing_area = gtk_drawing_area_new();
            gtk_widget_set_size_request(drawing_area, 60, 60);
            button_data = g_malloc(sizeof(ButtonData));
            button_data->row = i;
            button_data->col = j;
            button_data->is_pressed = FALSE;
            // GtkWidget *button=gtk_button_new();
            // Initialize piece widget with NULL
            button_data->piece = NULL;
            // button_data->button=button;

            button_data_grid[i][j] = button_data; // Store button data in grid

            g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_callback), button_data);
            g_signal_connect(G_OBJECT(drawing_area), "button-press-event", G_CALLBACK(button_press_event_callback), button_data);
            gtk_widget_set_events(drawing_area, GDK_BUTTON_PRESS_MASK);
            gtk_grid_attach(GTK_GRID(grid), drawing_area, j, i, 1, 1);
            // gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            
        }
    }

    // Add the grid to the fixed container at a specific position
    gtk_fixed_put(GTK_FIXED(fixed), grid, 50, 50); // Moves the grid to (50, 50) within the window

    // Adding chess pieces at their initial positions
    // Path to the chess pieces images
    char* piece_path = "C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\";
    
// Load and place chess pieces
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (strlen(chess_pieces[i][j]) > 0) {
                char filepath[256];
                snprintf(filepath, sizeof(filepath), "%s%s", piece_path, chess_pieces[i][j]);
                GtkWidget *image = gtk_image_new_from_file(filepath);
                if (!image) {
                    g_print("Failed to load image: %s\n", filepath);
                } else {
                    gtk_fixed_put(GTK_FIXED(fixed), image, 50 + j * 60, 50 + i * 60);
                    // Update button data to reference the piece image
                    button_data_grid[i][j]->piece = image;
                }
            }
        }
    }

    // Add a "Back" button to return to the "Choose Mode" window
    back_button = gtk_button_new_with_label("Back");
    g_signal_connect(back_button, "clicked", G_CALLBACK(go_back_to_choose_mode), window);
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 2, 2);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    for (GList *l = removed_pieces; l != NULL; l = l->next) {
    RemovedPiece *removed_piece = (RemovedPiece *)l->data;
    gtk_widget_show(removed_piece->piece);
    button_data_grid[removed_piece->row][removed_piece->col]->piece = removed_piece->piece;
    g_free(removed_piece);
}
g_list_free(removed_pieces);
removed_pieces = NULL;
}
void open_pvp_chessboard(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *background_area;
    GtkWidget *grid;
    GtkWidget *drawing_area;
    GtkWidget *back_button;
    ButtonData *button_data;
    GtkWidget *background_image;
    int i, j;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "PvP Mode");
    gtk_window_set_default_size(GTK_WINDOW(window), 580, 680);
    gtk_window_move(GTK_WINDOW(window), 700, 100);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Load and add the background image
    char* image_path = "C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\chess3.png"; // Update the path to your image file
    background_image = gtk_image_new_from_file(image_path);
    gtk_fixed_put(GTK_FIXED(fixed), background_image, 0, 0);
   
    grid = gtk_grid_new();

    // Draw dark brown border around chessboard
    GtkWidget *border_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(border_area, 500, 500);
    g_signal_connect(border_area, "draw", G_CALLBACK(draw_border), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), border_area, 40, 40); // Position the border area around the grid

    // Create 64 drawing areas (8x8 grid)
    ButtonData *button_data_grid[8][8]; // To store button data for each grid cell
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            drawing_area = gtk_drawing_area_new();
            gtk_widget_set_size_request(drawing_area, 60, 60);
            button_data = g_malloc(sizeof(ButtonData));
            button_data->row = i;
            button_data->col = j;
            button_data->is_pressed = FALSE;

            // Initialize piece widget with NULL
            button_data->piece = NULL;

            button_data_grid[i][j] = button_data; // Store button data in grid

            g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_callback), button_data);
            g_signal_connect(G_OBJECT(drawing_area), "button-press-event", G_CALLBACK(pvp_button_press_event_callback), button_data);
            gtk_widget_set_events(drawing_area, GDK_BUTTON_PRESS_MASK);
            gtk_grid_attach(GTK_GRID(grid), drawing_area, j, i, 1, 1);
        }
    }

    // Add the grid to the fixed container at a specific position
    gtk_fixed_put(GTK_FIXED(fixed), grid, 50, 50); // Moves the grid to (50, 50) within the window

    // Adding chess pieces at their initial positions
    // Path to the chess pieces images
    char* piece_path = "C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\";
    
// Load and place chess pieces
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (strlen(chess_pieces[i][j]) > 0) {
                char filepath[256];
                snprintf(filepath, sizeof(filepath), "%s%s", piece_path, chess_pieces[i][j]);
                GtkWidget *image = gtk_image_new_from_file(filepath);
                if (!image) {
                    g_print("Failed to load image: %s\n", filepath);
                } else {
                    gtk_fixed_put(GTK_FIXED(fixed), image, 50 + j * 60, 50 + i * 60);
                    // Update button data to reference the piece image
                    button_data_grid[i][j]->piece = image;
                }
            }
        }
    }

    // Add a "Back" button to return to the "Choose Mode" window
    back_button = gtk_button_new_with_label("Back");
    g_signal_connect(back_button, "clicked", G_CALLBACK(go_back_to_choose_mode), window);
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 2, 2);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    for (GList *l = removed_pieces; l != NULL; l = l->next) {
    RemovedPiece *removed_piece = (RemovedPiece *)l->data;
    gtk_widget_show(removed_piece->piece);
    button_data_grid[removed_piece->row][removed_piece->col]->piece = removed_piece->piece;
    g_free(removed_piece);
}
g_list_free(removed_pieces);
removed_pieces = NULL;
}
void go_back_to_choose_mode(GtkWidget *widget, gpointer data) {
    if (mode_window != NULL) {
        gtk_widget_destroy(mode_window);
    }
    GtkWidget *window = (GtkWidget *)data;
    gtk_widget_destroy(window);
    activate(GTK_APPLICATION(gtk_window_get_application(GTK_WINDOW(window))), NULL);
}
gboolean draw_border(GtkWidget *widget, cairo_t *cr, gpointer data) {
    // Set the color for the border (dark brown)
    cairo_set_source_rgb(cr, 0.36, 0.25, 0.20); // RGB values for dark brown color
    cairo_set_line_width(cr, 30); // Border width
    cairo_rectangle(cr, 10, 10, 480, 480); // Drawing a rectangle around the grid area
    cairo_stroke(cr); // Apply the stroke
    return FALSE;
}
gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
    ButtonData *button_data = (ButtonData *)data;
    // Set color based on the position and press state
    if (button_data->is_pressed) {
        if ((button_data->row + button_data->col) % 2==0) {
            cairo_set_source_rgb(cr, 0, 1, 0); // purplish

        } else {
            cairo_set_source_rgb(cr, 0, 1, 0); // purplish

        }
    } else if ((button_data->row + button_data->col) % 2==0) {
        cairo_set_source_rgb(cr, .55, .62, .45); // white
    } else {
        cairo_set_source_rgb(cr, .24, .62, .32); // light black
    }
    cairo_paint(cr); // Fill the entire area with the color
    // Check if the current button is in the possible_moves array and draw a circle if so
    for (int i = 0; i < num_possible_moves; i++) {
        if (possible_moves[i][0] == button_data->row && possible_moves[i][1] == button_data->col) {
            if (button_data->piece) {
                cairo_set_source_rgb(cr, 1, 0, 0); // red for squares with a piece
                cairo_arc(cr, 30, 30, 50, 0, 2 * G_PI); // Draw a circle of radius 24px at the center (30, 30) of the square
            } else {
                cairo_set_source_rgb(cr, 0, 0, 1); // blue for empty squares
                cairo_arc(cr, 30, 30, 12, 0, 2 * G_PI); // Draw a circle of radius 24px at the center (30, 30) of the square
            }
            
            cairo_fill(cr);
            break; // Exit the loop once the button is found in the possible_moves array
        }
    }
    
    // Check if the current button is in the possible_moves array and draw a circle if so
    // for (int i = 0; i < num_possible_moves; i++) {
    //     if (possible_moves[i][0] == button_data->row && possible_moves[i][1] == button_data->col) {
    //         cairo_set_source_rgb(cr, 255, 0, 0); // Purplish color for the circle
    //         cairo_arc(cr, 30, 30, 24, 0, 2 * G_PI); // Draw a circle of radius 10px at the center (30, 30) of the square
    //         cairo_fill(cr);
    //         break; // Exit the loop once the button is found in the possible_moves array
    //     }
    // }

    return FALSE; // Return FALSE to indicate no further drawing is needed
}
void simulate_button_press(GtkWidget *grid, int row, int col) {
    GtkWidget *widget = gtk_grid_get_child_at(GTK_GRID(grid), col, row);
    if (!widget) {
        g_print("No widget found at (%d, %d)\n", row, col);
        return;
    }
    GdkEvent *event = gdk_event_new(GDK_BUTTON_PRESS);
    event->button.type = GDK_BUTTON_PRESS;
    event->button.window = gtk_widget_get_window(widget);
    g_object_ref(event->button.window);
    event->button.send_event = TRUE;
    event->button.time = GDK_CURRENT_TIME;
    event->button.x = 1.0;
    event->button.y = 1.0;
    event->button.axes = NULL;
    event->button.state = 0;
    event->button.button = 1;
    event->button.device = gdk_seat_get_pointer(gdk_display_get_default_seat(gdk_display_get_default()));
    event->button.x_root = 1.0;
    event->button.y_root = 1.0;
    gdk_event_set_device(event, event->button.device);

    gtk_widget_event(widget, event);
    gdk_event_free(event);

    gtk_widget_queue_draw(widget);
    gtk_widget_queue_draw(grid);
}
void show_secondary_window_white() {
    GtkWidget *secondary_window_white;
    GtkWidget *image;
    GtkWidget *fixed;

    secondary_window_white = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(secondary_window_white), "CHECKMATE");
    gtk_window_set_default_size(GTK_WINDOW(secondary_window_white), 400, 200);
    gtk_window_move(GTK_WINDOW(secondary_window_white), 790, 220);

    // Create a fixed container
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(secondary_window_white), fixed);

    // Load the image
    image = gtk_image_new_from_file("C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\w.png");
    gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);
    gtk_widget_show_all(secondary_window_white);
}
void show_secondary_window_black() {
    GtkWidget *secondary_window_black;
    GtkWidget *image;
    GtkWidget *fixed;

    secondary_window_black = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(secondary_window_black), "CHECKMATE_black");
    gtk_window_set_default_size(GTK_WINDOW(secondary_window_black), 400, 200);
    gtk_window_move(GTK_WINDOW(secondary_window_black), 790, 220);

    // Create a fixed container
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(secondary_window_black), fixed);

    // Load the image
    image = gtk_image_new_from_file("C:\\msys64\\mingw64\\lib\\chessbot\\first\\chess_pieces\\b.png");
    gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);
    gtk_widget_show_all(secondary_window_black);
}
void show_check_window(){
    GtkWidget *check_window;
    check_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(check_window), "CHECK");
    gtk_window_set_default_size(GTK_WINDOW(check_window), 200, 100);
    gtk_window_move(GTK_WINDOW(check_window), 890, 300);
    GtkWidget *label ;
    // Create a woodish background
    GdkRGBA woodish_color;
    gdk_rgba_parse(&woodish_color, "#4682B4"); // SaddleBrown color for woodish effect
    gtk_widget_override_background_color(check_window, GTK_STATE_FLAG_NORMAL, &woodish_color);

    // Create the label at the center top
    label = gtk_label_new("CHECK!!");
    PangoFontDescription *font_desc = pango_font_description_from_string("Sans Bold 40");
    gtk_widget_override_font(label, font_desc);
    pango_font_description_free(font_desc);
    gtk_widget_set_name(label, "glow_label");
    gtk_container_add(GTK_CONTAINER(check_window), label);
    gtk_widget_show_all(check_window);
}
gboolean button_press_event_callback(GtkWidget *widget, GdkEventButton *event, gpointer data) {
    ButtonData *button_data = (ButtonData *)data;
    g_print("Button at (%d, %d) pressed\n", button_data->row, button_data->col);

    char* ppiece = chess_pieces[button_data->row][button_data->col];
    if (strlen(ppiece) > 0) {
        g_print("%s\n\n", ppiece);
    } else {
        g_print("empty\n\n");
    }
    if(current_turn==WHITE_TURN){
        if (first_pressed_button == button_data) {
            // Deselect the piece if clicked again
            first_pressed_button->is_pressed = FALSE;
            first_pressed_button = NULL;
            g_print("Deselected piece at (%d, %d)\n", button_data->row, button_data->col);
            // Clear possible moves to remove circles
            num_possible_moves = 0;
            GtkWidget *grid = gtk_widget_get_parent(widget);
            gtk_widget_queue_draw(grid);
        } else if (!first_pressed_button && button_data->piece) {
            // Check if it's the correct turn for this piece
            gboolean valid_turn = FALSE;
            if (current_turn == WHITE_TURN && (strcmp(ppiece, p) == 0 || strcmp(ppiece, a) == 0 || strcmp(ppiece, b) == 0 || strcmp(ppiece, c) == 0 || strcmp(ppiece, d) == 0 || strcmp(ppiece, e) == 0)) {
                valid_turn = TRUE;
            }
           if(valid_turn){
            // If this button has a piece, select it
            first_pressed_button = button_data;
            if (strcmp(chess_pieces[button_data->row][button_data->col], p) == 0) {
                pawn_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            if (strcmp(chess_pieces[button_data->row][button_data->col], a) == 0) {
                rook_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            if (strcmp(chess_pieces[button_data->row][button_data->col], b) == 0) {
                knight_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            if (strcmp(chess_pieces[button_data->row][button_data->col], c) == 0) {
                bishop_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            if (strcmp(chess_pieces[button_data->row][button_data->col], d) == 0) {
                queen_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            if (strcmp(chess_pieces[button_data->row][button_data->col], e) == 0) {
                king_moves_white(button_data->row, button_data->col, chess_pieces);
                filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
            }
            button_data->is_pressed = TRUE;
            GtkWidget *grid = gtk_widget_get_parent(widget);
            gtk_widget_queue_draw(grid); // Redraw the entire grid to show circles immediately
            
        }} else if (first_pressed_button) {
            // Check if the target position is in the possible moves
            gboolean valid_move = FALSE;
            for (int i = 0; i < num_possible_moves; i++) {
                if (possible_moves[i][0] == button_data->row && possible_moves[i][1] == button_data->col) {
                    valid_move = TRUE;
                    break;
                }
            }
            // if(checkmate_black==0) valid_move=FALSE;

            if (valid_move) {
                // If there's a selected piece and this button is occupied, remove the existing piece temporarily
                if (button_data->piece) {
                    RemovedPiece *removed_piece = g_malloc(sizeof(RemovedPiece));
                    removed_piece->piece = button_data->piece;
                    removed_piece->row = button_data->row;
                    removed_piece->col = button_data->col;
                    removed_pieces = g_list_prepend(removed_pieces, removed_piece);
                    gtk_widget_hide(button_data->piece);
                    button_data->piece = NULL;
                }
                // Move the piece
                gtk_fixed_move(GTK_FIXED(gtk_widget_get_parent(first_pressed_button->piece)), first_pressed_button->piece, 50 + button_data->col * 60, 50 + button_data->row * 60);
                button_data->piece = first_pressed_button->piece;
                // Update the chess_pieces array
                chess_pieces[button_data->row][button_data->col] = chess_pieces[first_pressed_button->row][first_pressed_button->col]; // Set the new position to the moved piece name
                chess_pieces[first_pressed_button->row][first_pressed_button->col] = ""; // Set the original position to empty
                first_pressed_button->piece = NULL;
                first_pressed_button->is_pressed = FALSE;
                first_pressed_button = NULL;
                num_possible_moves = 0;
                GtkWidget *grid = gtk_widget_get_parent(widget);
                gtk_widget_queue_draw(grid); 
                if(check_white(chess_pieces)==0) show_check_window();
                if(checkmate_black(chess_pieces)==1) show_secondary_window_black();
                current_turn=BLACK_TURN;
            }
            if(current_turn==BLACK_TURN){
                    ai_random(chess_pieces);
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    simulate_button_press(grid,x,y);
                    gtk_widget_queue_draw(grid);
                    num_possible_moves=0;
                    simulate_button_press(grid,bot_move_random[0],bot_move_random[1]);
                    gtk_widget_queue_draw(grid);
                    random=1;
                    
            }

            current_turn=WHITE_TURN;
        }
        return TRUE;
    }
    if(current_turn==BLACK_TURN){
        if (first_pressed_button == button_data) {
            // Deselect the piece if clicked again
            first_pressed_button->is_pressed = FALSE;
            first_pressed_button = NULL;
            g_print("Deselected piece at (%d, %d)\n", button_data->row, button_data->col);
            // Clear possible moves to remove circles
            num_possible_moves = 0;
            GtkWidget *grid = gtk_widget_get_parent(widget);
            gtk_widget_queue_draw(grid);
        } else if (!first_pressed_button && button_data->piece) {
            // If this button has a piece, select it
            first_pressed_button = button_data;
            if(random!=0){
                if (strcmp(chess_pieces[button_data->row][button_data->col], P) == 0) {
                    pawn_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
                if (strcmp(chess_pieces[button_data->row][button_data->col], A) == 0) {
                    rook_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
                if (strcmp(chess_pieces[button_data->row][button_data->col], B) == 0) {
                    knight_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
                if (strcmp(chess_pieces[button_data->row][button_data->col], C) == 0) {
                    bishop_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
                if (strcmp(chess_pieces[button_data->row][button_data->col], D) == 0) {
                    queen_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
                if (strcmp(chess_pieces[button_data->row][button_data->col], E) == 0) {
                    king_moves_black(button_data->row, button_data->col, chess_pieces);
                    filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
                    button_data->is_pressed = TRUE;
                    GtkWidget *grid = gtk_widget_get_parent(widget);
                    gtk_widget_queue_draw(grid);
                    random_move(num_possible_moves,possible_moves);
                }
            }
        } else if (first_pressed_button) {
                if (button_data->piece) {
                    RemovedPiece *removed_piece = g_malloc(sizeof(RemovedPiece));
                    removed_piece->piece = button_data->piece;
                    removed_piece->row = button_data->row;
                    removed_piece->col = button_data->col;
                    removed_pieces = g_list_prepend(removed_pieces, removed_piece);
                    gtk_widget_hide(button_data->piece);
                    button_data->piece = NULL;
                }
                // Move the piece
                gtk_fixed_move(GTK_FIXED(gtk_widget_get_parent(first_pressed_button->piece)), first_pressed_button->piece, 50 + button_data->col * 60, 50 + button_data->row * 60);
                button_data->piece = first_pressed_button->piece;
                // Update the chess_pieces array
                chess_pieces[button_data->row][button_data->col] = chess_pieces[first_pressed_button->row][first_pressed_button->col]; // Set the new position to the moved piece name
                chess_pieces[first_pressed_button->row][first_pressed_button->col] = ""; // Set the original position to empty
                first_pressed_button->piece = NULL;
                first_pressed_button->is_pressed = FALSE;
                first_pressed_button = NULL;
                num_possible_moves = 0; 
                GtkWidget *grid = gtk_widget_get_parent(widget);
                gtk_widget_queue_draw(grid);
                // if(check_black(chess_pieces)==0) printf("check");
                if(check_white(chess_pieces)==0) show_check_window();
                if(checkmate_white(chess_pieces)==1) show_secondary_window_white();
        }
        return TRUE;
    }
}
gboolean pvp_button_press_event_callback(GtkWidget *widget, GdkEventButton *event, gpointer data) {
    ButtonData *button_data = (ButtonData *)data;
    g_print("Button at (%d, %d) pressed\n", button_data->row, button_data->col);

    char* ppiece = chess_pieces[button_data->row][button_data->col];
    if (strlen(ppiece) > 0) {
        g_print("%s\n\n", ppiece);
    } else {
        g_print("empty\n\n");
    }

    if (first_pressed_button == button_data) {
        // Deselect the piece if clicked again
        first_pressed_button->is_pressed = FALSE;
        first_pressed_button = NULL;
        g_print("Deselected piece at (%d, %d)\n", button_data->row, button_data->col);
        // Clear possible moves to remove circles
        num_possible_moves = 0;
        GtkWidget *grid = gtk_widget_get_parent(widget);
        gtk_widget_queue_draw(grid);
    } else if (!first_pressed_button && button_data->piece) {
        // Check if it's the correct turn for this piece
        gboolean valid_turn = FALSE;
        if (current_turn == WHITE_TURN && (strcmp(ppiece, p) == 0 || strcmp(ppiece, a) == 0 || strcmp(ppiece, b) == 0 || strcmp(ppiece, c) == 0 || strcmp(ppiece, d) == 0 || strcmp(ppiece, e) == 0)) {
            valid_turn = TRUE;
        } else if (current_turn == BLACK_TURN && (strcmp(ppiece, P) == 0 || strcmp(ppiece, A) == 0 || strcmp(ppiece, B) == 0 || strcmp(ppiece, C) == 0 || strcmp(ppiece, D) == 0 || strcmp(ppiece, E) == 0)) {
            valid_turn = TRUE;
        }
       if(valid_turn){
        // If this button has a piece, select it
        first_pressed_button = button_data;
        if (strcmp(chess_pieces[button_data->row][button_data->col], p) == 0) {
            pawn_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], P) == 0) {
            pawn_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], A) == 0) {
            rook_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], a) == 0) {
            rook_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], b) == 0) {
            knight_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], B) == 0) {
            knight_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], c) == 0) {
            bishop_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], C) == 0) {
            bishop_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], d) == 0) {
            queen_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], D) == 0) {
            queen_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], e) == 0) {
            king_moves_white(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_white(button_data->row, button_data->col,chess_pieces);
        }
        if (strcmp(chess_pieces[button_data->row][button_data->col], E) == 0) {
            king_moves_black(button_data->row, button_data->col, chess_pieces);
            filter_invalid_moves_black(button_data->row, button_data->col,chess_pieces);
        }
        button_data->is_pressed = TRUE;
        // if(checkmate_black(chess_pieces)!=0){
        GtkWidget *grid = gtk_widget_get_parent(widget);
        gtk_widget_queue_draw(grid); // Redraw the entire grid to show circles immediately
        // }
        // else printf("check");
    }} else if (first_pressed_button) {
        // Check if the target position is in the possible moves
        gboolean valid_move = FALSE;
        for (int i = 0; i < num_possible_moves; i++) {
            if (possible_moves[i][0] == button_data->row && possible_moves[i][1] == button_data->col) {
                valid_move = TRUE;
                break;
            }
        }
        // if(checkmate_black==0) valid_move=FALSE;

        if (valid_move) {
            // If there's a selected piece and this button is occupied, remove the existing piece temporarily
            if (button_data->piece) {
                RemovedPiece *removed_piece = g_malloc(sizeof(RemovedPiece));
                removed_piece->piece = button_data->piece;
                removed_piece->row = button_data->row;
                removed_piece->col = button_data->col;
                removed_pieces = g_list_prepend(removed_pieces, removed_piece);
                gtk_widget_hide(button_data->piece);
                button_data->piece = NULL;
            }
            // Move the piece
            gtk_fixed_move(GTK_FIXED(gtk_widget_get_parent(first_pressed_button->piece)), first_pressed_button->piece, 50 + button_data->col * 60, 50 + button_data->row * 60);
            button_data->piece = first_pressed_button->piece;
            // Update the chess_pieces array
            chess_pieces[button_data->row][button_data->col] = chess_pieces[first_pressed_button->row][first_pressed_button->col]; // Set the new position to the moved piece name
            chess_pieces[first_pressed_button->row][first_pressed_button->col] = ""; // Set the original position to empty
            first_pressed_button->piece = NULL;
            first_pressed_button->is_pressed = FALSE;
            first_pressed_button = NULL;
            num_possible_moves = 0; // Clear possible moves to remove circles
            GtkWidget *grid = gtk_widget_get_parent(widget);
            int z;
            if(current_turn==WHITE_TURN) if((checkmate_black(chess_pieces)==1)) { show_secondary_window_black();z=0;}
            if(current_turn==BLACK_TURN) if((checkmate_white(chess_pieces)==1)) { show_secondary_window_white();z=0;}
            if(check_black(chess_pieces)==0&&z!=0) show_check_window();
            if(check_white(chess_pieces)==0&&z!=0) show_check_window();
            // Switch turn
            gtk_widget_queue_draw(grid); // Redraw the entire grid to show circles immediately
            current_turn = (current_turn == WHITE_TURN) ? BLACK_TURN : WHITE_TURN;
        }
    }
    return TRUE;
}

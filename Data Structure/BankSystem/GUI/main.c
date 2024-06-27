#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client.h"

#define ID_ADD_CLIENT_BUTTON 101
#define ID_DISPLAY_BUTTON 102
#define ID_DELETE_BUTTON 103
#define ID_ADD_BALANCE_BUTTON 104
#define ID_DEPOSIT_BUTTON 105
#define ID_EXIT_BUTTON 106
#define ID_OUTPUT_WINDOW 107

HWND hwndOutput;
client *head = nullptr;

void display_all(client *head, HWND hwndOutput) {
    if (!head) {
        SetWindowTextA(hwndOutput, "No clients in the bank\n");
    } else {
        client *temp = head;
        char buffer[4096] = ""; // Buffer to store the concatenated client data

        while (temp && temp->id >= 0) {
            char tempBuffer[512];
            sprintf(tempBuffer,
                    "Client Data:\r\nName: %s\r\nPassword: %s\r\nBalance: %.2lf\r\nID: %d\r\n---------------------------------\r\n",

                    temp->name, temp->password, temp->balance, temp->id);
            strcat(buffer, tempBuffer); // Concatenate client data to the buffer
            temp = temp->next;
            Sleep(2000); // Sleep for 2 seconds
        }

        SetWindowTextA(hwndOutput, buffer); // Set the text of the window
    }
}

void AddClient(HWND hwndOutput) {
    Add_newClient(&head);
    display_all(head, hwndOutput);
}

void DeleteClient(HWND hwndOutput) {
    int id;
    printf("Enter the id of the client to delete: ");
    scanf("%d", &id);
    Delete_client(&head, id);
    display_all(head, hwndOutput);
}

// Add functions for other button actions similarly

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE: {
            hwndOutput = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                        WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
                                        10, 10, 400, 280, hwnd, (HMENU) ID_OUTPUT_WINDOW, NULL, NULL);

            // Calculate button size and spacing
            int buttonWidth = 100;
            int buttonHeight = 30;
            int buttonSpacingX = 20;
            int buttonSpacingY = 10;

            // Calculate the top-left position of the button matrix
            int matrixTopLeftX = (430 - (buttonWidth * 2 + buttonSpacingX)) / 2;
            int matrixTopLeftY = 300;

            // Create the buttons in a 2x3 matrix layout
            CreateWindow("BUTTON", "Add Client", WS_VISIBLE | WS_CHILD, matrixTopLeftX, matrixTopLeftY, buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_ADD_CLIENT_BUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Display Clients", WS_VISIBLE | WS_CHILD, matrixTopLeftX + buttonWidth + buttonSpacingX, matrixTopLeftY, buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_DISPLAY_BUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Delete Client", WS_VISIBLE | WS_CHILD, matrixTopLeftX, matrixTopLeftY + buttonHeight + buttonSpacingY, buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_DELETE_BUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Add Balance", WS_VISIBLE | WS_CHILD, matrixTopLeftX + buttonWidth + buttonSpacingX, matrixTopLeftY + buttonHeight + buttonSpacingY, buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_ADD_BALANCE_BUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Deposit", WS_VISIBLE | WS_CHILD, matrixTopLeftX, matrixTopLeftY + 2 * (buttonHeight + buttonSpacingY), buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_DEPOSIT_BUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Exit", WS_VISIBLE | WS_CHILD, matrixTopLeftX + buttonWidth + buttonSpacingX, matrixTopLeftY + 2 * (buttonHeight + buttonSpacingY), buttonWidth, buttonHeight, hwnd,
                         (HMENU) ID_EXIT_BUTTON, NULL, NULL);

            // Update the size of the window
            RECT rcClient, rcWindow;
            GetClientRect(hwnd, &rcClient);
            GetWindowRect(hwnd, &rcWindow);
            int xPos = (GetSystemMetrics(SM_CXSCREEN) - (rcWindow.right - rcWindow.left)) / 2;
            int yPos = (GetSystemMetrics(SM_CYSCREEN) - (rcWindow.bottom - rcWindow.top)) / 2;
            MoveWindow(hwnd, xPos, yPos, 430, 570, TRUE);

            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case ID_ADD_CLIENT_BUTTON: {
                    AddClient(hwndOutput);
                    break;
                }
                case ID_DISPLAY_BUTTON: {
                    display_all(head, hwndOutput);
                    break;
                }
                case ID_DELETE_BUTTON: {
                    DeleteClient(hwndOutput);
                    break;
                }
                case ID_ADD_BALANCE_BUTTON: {
                    Add_Balance(head);
                    display_all(head, hwndOutput);
                    break;
                }
                case ID_DEPOSIT_BUTTON: {
                    Deposit(head);
                    display_all(head, hwndOutput);
                    break;
                }
                case ID_EXIT_BUTTON: {
                    PostQuitMessage(0);
                    break;

                }



                    // Handle other button events similarly
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default: {
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    head = Create_Admin_Client(); // Create admin client

    WNDCLASSEX wc = {sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WindowProcedure, 0, 0, hInstance,
                     LoadIcon(NULL, IDI_APPLICATION),
                     LoadCursor(NULL, IDC_ARROW), (HBRUSH) (COLOR_WINDOW + 1), NULL, "BankSystemClass",
                     LoadIcon(NULL, IDI_APPLICATION)};
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(0, "BankSystemClass", "Bank System", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 430, 370, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    free(head);
    return msg.wParam;
}

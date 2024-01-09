#include <bits/stdc++.h>
#include "tgbot/tgbot.h"
using namespace std;
using namespace TgBot;

int main(){
    auto bot = Bot("5769859964:AAEynJeldbDcJqDAPrjUbLjxwqCrjrgGqsQ");
    cout << "Start\n";
    bot.getEvents().onAnyMessage([&](Message* message){
        auto chat_id message->chat->id;
        bot.getApi().sendMessage(chat_id,"Hola\n");
    });
}
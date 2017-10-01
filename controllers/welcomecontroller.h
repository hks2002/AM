#ifndef WELCOME_H
#define WELCOME_H
#include <TActionController>

class T_CONTROLLER_EXPORT WelcomeController : public TActionController
{
    Q_OBJECT
public:
    WelcomeController() : TActionController() { }

public slots:
    void index();
    void signIn();
    void logOut();
    void logIn();
    void forgetPassword();
};

#endif // WELCOME_H

interface QuackBehaviour {
    void quack();
}

class NormalQuack implements QuackBehaviour {
    void quack () {
        //quack
    }
}

class Mute implements QuackBehaviour {
    void quack () {
        //silent
    }
}
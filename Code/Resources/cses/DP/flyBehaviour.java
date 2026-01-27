interface FlyBehaviour {
    void quack();
}

class FlyWithWings implements FlyBehaviour {
    void fly () {
        //fly with wings
    }
}

class NoFly implements FlyBehaviour {
    void fly () {
        //down to earth
    }
}
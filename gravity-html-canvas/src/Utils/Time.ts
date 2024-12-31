import { EventEmitter } from 'events';
import * as THREE from 'three';

export default class Time extends EventEmitter {
    private clock = new THREE.Clock();
    private start = Date.now();
    private current = this.start;
    public elapsed = 0;
    public elapsedTime = this.clock.getElapsedTime();
    public delta = 16;

    constructor() {
        super();

        this.update();
    }

    update() {
        const currentTime = Date.now();
        this.delta = currentTime - this.current;
        this.current = currentTime;
        this.elapsed = this.current - this.start;
        this.elapsedTime = this.clock.getElapsedTime();

        this.emit('update');
        window.requestAnimationFrame(this.update.bind(this));
    }
}
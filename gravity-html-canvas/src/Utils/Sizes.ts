import { EventEmitter } from "events"


export default class Sizes extends EventEmitter {
    public width: number = window.innerWidth;
    public height: number = window.innerHeight;

    constructor() {
        super();
        window.addEventListener("resize", () => {
            this.width = window.innerWidth;
            this.height = window.innerHeight;
            this.emit('resize');
        })
    }
}
// import "./Utils/Utils"
import Sizes from "../../Utils/Sizes";
import Time from "../../Utils/Time";
import { World } from "../World";

export default class Experience {
    static #instance: Experience;
    public canvas: HTMLCanvasElement = <HTMLCanvasElement>document.querySelector("canvas");
    public context: CanvasRenderingContext2D | null = this.canvas.getContext('2d');
    public sizes: Sizes | undefined;
    public time: Time | undefined;
    public world: World | undefined;


    constructor() {
        if (Experience.#instance) {
            return Experience.#instance;
        } else {
            Experience.#instance = this;

            this.canvas.width = window.innerWidth
            this.canvas.height = window.innerHeight;

            this.time = new Time();
            this.sizes = new Sizes();
            this.world = new World();

            this.time.on("update", () => {
                this.update();
            });

            this.sizes.on("resize", () => {
                this.resize();
            })
        }
    }

    public resize() {
        this.canvas.width = window.innerWidth
        this.canvas.height = window.innerHeight;
        this.world!.resize();
    }

    public update() {
        this.world!.update();
    }







}
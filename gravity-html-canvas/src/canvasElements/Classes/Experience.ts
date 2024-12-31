// import "./Utils/Utils"
import Sizes from "../../Utils/Sizes";
import Time from "../../Utils/Time";
import World from "../World";

export default class Experience {
    static #instance: Experience;
    public canvas: HTMLCanvasElement = <HTMLCanvasElement>document.querySelector("canvas");
    public context: CanvasRenderingContext2D | null = this.canvas.getContext('2d');
    public sizes: Sizes;
    public time: Time;
    public world: World;


    constructor() {
        if (Experience.#instance) {
            return Experience.#instance;
        }
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

    public resize() {
        this.canvas.width = window.innerWidth
        this.canvas.height = window.innerHeight;
    }

    public update() {
        this.world.update();
    }







}
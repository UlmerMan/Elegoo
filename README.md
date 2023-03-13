# About

This is a library for Elegoo Smart Car Robot Kit.

## Getting Started

### Commands

|                         **Command**                          | **Explenation**                                              |
| :----------------------------------------------------------: | ------------------------------------------------------------ |
|          Constructor<br />e. g. elegoo car(version)          | You have to put the version in quotes in the brackets. You can see the Supported Versions in the table below. |
| forward() <br />backward()<br>  left()<br>  right()<br>  stop() | These arguments explain themselves. Into the brackets you can put a number between 1 and 256 for the speed. The default speed is 255. |
|  forwardT() <br>   backwardT() <br>   leftT() <br>rightT()   | The arguments function just like the others but you have to put the time and the speed into the brackets. <br> With a syntax like this: <br> ``` car.forwardT(SPEED, TIME); ``` <br>You can choose a number between 1 and 255. |
|                        getDistance()                         | This is a function to get the distance from the Ultrasonic sensor. It returns it as an Integer. |

## Supported Versions

| Version | Comment                                                  |
| ------- | -------------------------------------------------------- |
| v1      | e. g. elegoo car ("v1")    Elegoo Smart Car Robot Kit v1 |
| v2      | e. g. elegoo car ("v2")    Elegoo Smart Car Robot Kit v2 |
| v3      | e. g. elegoo car ("v3")    Elegoo Smart Car Robot Kit v3 |
| v4.0    | e. g. elegoo car ("v4.0")  **!!!work in progress!!!**    |
| v4.1    | e. g. elegoo car ("v4.1")  **!!!work in progress!!!**    |
| v4.2    | e. g. elegoo car ("v4.2")  **!!!work in progress!!!**    |



<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repository and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request


const path = require("path");

module.exports = [
  {
    name: "@storybook/preset-typescript",
    options: {
      transpileManager: true,
      tsLoaderOptions: {
        configFile: path.resolve(__dirname, "../tsconfig.json"),
      },
      tsDocgenLoaderOptions: {
        tsconfigPath: path.resolve(__dirname, "../tsconfig.json"),
      },
      include: [path.resolve(__dirname, "../src")],
    },
  },
  {
    name: "@storybook/addon-docs/react/preset",
    options: {
      configureJSX: true,
      babelOptions: {},
      sourceLoaderOptions: null,
    },
  },
];

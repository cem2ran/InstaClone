const { resolve } = require("path");
const { withUnimodules } = require("@expo/webpack-config/addons");

module.exports = async ({ config }) => {
  // config.module.rules.push({
  //   test: /\.(ts|tsx)$/,
  //   loader: require.resolve("babel-loader"),
  //   options: {
  //     presets: [["react-app", { flow: false, typescript: true }]],
  //   },
  // });
  // config.resolve.extensions.push(".ts", ".tsx");

  config.module.rules.push({
    test: /\.(ts|tsx)$/,
    use: [
      {
        loader: require.resolve("babel-loader"),
        options: {
          presets: [["react-app", { flow: false, typescript: true }]],
        },
      },
      {
        loader: require.resolve("react-docgen-typescript-loader"),
      },
    ],
  });

  // config.module.rules.push({
  //   test: /\.(ts|tsx)$/,
  //   use: [
  //     {
  //       loader: require.resolve("ts-loader"),
  //       options: {
  //         configFile: "../tsconfig.json",
  //         // transpileOnly: true,
  //         // experimentalWatchApi: true,
  //         // experimentalFileCaching: true,
  //         // happyPackMode: true,
  //       },
  //     },
  //     // Optional

  //   ],
  // });
  config.resolve.extensions.push(".ts", ".tsx");
  // return config;
  const custom = withUnimodules(config, {
    projectRoot: resolve(__dirname, "../"),
  });

  return {
    ...config,
    module: { ...config.module, rules: custom.module.rules },
  };
};

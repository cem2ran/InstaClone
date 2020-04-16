import * as React from "react";

import { storiesOf } from "@storybook/react-native";
import { SafeAreaView } from "react-native";

import Post from "./Post.gen";
import { navigationDecorator, apolloMocks } from "../../.storybook/fixtures";

const safeAreaDecorator = (storyFn) => (
  <SafeAreaView style={{ flex: 1 }}>{storyFn()}</SafeAreaView>
);

// @ts-ignore
export const post = () => <Post route={{ params: "some_id" }} />;

const title = "Post";

export default {
  title,
  decorators: [navigationDecorator, safeAreaDecorator, apolloMocks()],
};

storiesOf(title, module)
  .addDecorator(navigationDecorator)
  .addDecorator(safeAreaDecorator)
  .addDecorator(apolloMocks())
  .add("Post", post);

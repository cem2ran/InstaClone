import * as React from 'react'

import { storiesOf } from '@storybook/react-native'
import { apolloMocks } from '../../fixtures'
import { Text, SafeAreaView } from 'react-native'

import Post from '../../../src/Post/Post.gen';
import {navigationDecorator} from "../Profile/ProfileStory";

const safeAreaDecorator = (
    storyFn,
) => <SafeAreaView style={{ flex: 1 }}>{storyFn()}</SafeAreaView>;

storiesOf('Post', module)
    .addDecorator(navigationDecorator)
    .addDecorator(safeAreaDecorator)
    .addDecorator(apolloMocks())
    .add('Some', () => <Post route={{params: "some_id"}} />)

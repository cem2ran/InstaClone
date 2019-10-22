import * as React from 'react'

import { storiesOf } from '@storybook/react-native'
import { apolloMocks } from '../../fixtures'
import { Text, SafeAreaView } from 'react-native'

import Posts from '../../../src/Profile/components/Posts.gen';

const safeAreaDecorator = (
    storyFn,
) => <SafeAreaView style={{ flex: 1 }}>{storyFn()}</SafeAreaView>;

storiesOf('Posts', module)
    .addDecorator(safeAreaDecorator)
    .addDecorator(apolloMocks())
    .add('Empty', () => <Posts navigateToPost={id => console.log("navigateToPost", id)} />)

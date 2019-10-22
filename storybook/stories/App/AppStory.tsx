import * as React from 'react'
import { storiesOf } from '@storybook/react-native'
import { app as App } from '../../../src/App.gen'
import { apolloMocks } from '../../fixtures'

storiesOf('App', module)
    .addDecorator(apolloMocks())
    .add('Profile', () => <App />)